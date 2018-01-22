// Compiled shader for Web Player, uncompressed size: 293.1KB

// Skipping shader variants that would not be included into build of current scene.

Shader "TMPro/Distance Field (Surface)" {
Properties {
 _FaceTex ("Fill Texture", 2D) = "white" { }
 _FaceUVSpeedX ("Face UV Speed X", Range(-5,5)) = 0
 _FaceUVSpeedY ("Face UV Speed Y", Range(-5,5)) = 0
 _FaceColor ("Fill Color", Color) = (1,1,1,1)
 _FaceDilate ("Face Dilate", Range(-1,1)) = 0
 _OutlineColor ("Outline Color", Color) = (0,0,0,1)
 _OutlineTex ("Outline Texture", 2D) = "white" { }
 _OutlineUVSpeedX ("Outline UV Speed X", Range(-5,5)) = 0
 _OutlineUVSpeedY ("Outline UV Speed Y", Range(-5,5)) = 0
 _OutlineWidth ("Outline Thickness", Range(0,1)) = 0
 _OutlineSoftness ("Outline Softness", Range(0,1)) = 0
 _Bevel ("Bevel", Range(0,1)) = 0.5
 _BevelOffset ("Bevel Offset", Range(-0.5,0.5)) = 0
 _BevelWidth ("Bevel Width", Range(-0.5,0.5)) = 0
 _BevelClamp ("Bevel Clamp", Range(0,1)) = 0
 _BevelRoundness ("Bevel Roundness", Range(0,1)) = 0
 _BumpMap ("Normalmap", 2D) = "bump" { }
 _BumpOutline ("Bump Outline", Range(0,1)) = 0.5
 _BumpFace ("Bump Face", Range(0,1)) = 0.5
 _ReflectFaceColor ("Face Color", Color) = (0,0,0,1)
 _ReflectOutlineColor ("Outline Color", Color) = (0,0,0,1)
 _Cube ("Reflection Cubemap", CUBE) = "black" { }
 _EnvMatrixRotation ("Texture Rotation", Vector) = (0,0,0,0)
 _SpecColor ("Specular Color", Color) = (0,0,0,1)
 _FaceShininess ("Face Shininess", Range(0,1)) = 0
 _OutlineShininess ("Outline Shininess", Range(0,1)) = 0
 _GlowColor ("Color", Color) = (0,1,0,0.5)
 _GlowOffset ("Offset", Range(-1,1)) = 0
 _GlowInner ("Inner", Range(0,1)) = 0.05
 _GlowOuter ("Outer", Range(0,1)) = 0.05
 _GlowPower ("Falloff", Range(1,0)) = 0.75
 _WeightNormal ("Weight Normal", Float) = 0
 _WeightBold ("Weight Bold", Float) = 0.5
 _ShaderFlags ("Flags", Float) = 0
 _ScaleRatioA ("Scale RatioA", Float) = 1
 _ScaleRatioB ("Scale RatioB", Float) = 1
 _ScaleRatioC ("Scale RatioC", Float) = 1
 _MainTex ("Font Atlas", 2D) = "white" { }
 _TextureWidth ("Texture Width", Float) = 512
 _TextureHeight ("Texture Height", Float) = 512
 _GradientScale ("Gradient Scale", Float) = 5
 _ScaleX ("Scale X", Float) = 1
 _ScaleY ("Scale Y", Float) = 1
 _PerspectiveFilter ("Perspective Correction", Range(0,1)) = 0.875
 _VertexOffsetX ("Vertex OffsetX", Float) = 0
 _VertexOffsetY ("Vertex OffsetY", Float) = 0
}
SubShader { 
 LOD 300
 Tags { "QUEUE"="Transparent" "IGNOREPROJECTOR"="true" "RenderType"="Transparent" }


 // Stats for Vertex shader:
 //       d3d11 : 92 avg math (80..104)
 //        d3d9 : 119 avg math (103..135)
 //      opengl : 155 math, 9 texture, 3 branch
 // Stats for Fragment shader:
 //       d3d11 : 125 math, 9 texture
 //        d3d9 : 170 math, 9 texture
 Pass {
  Name "FORWARD"
  Tags { "LIGHTMODE"="ForwardBase" "QUEUE"="Transparent" "IGNOREPROJECTOR"="true" "RenderType"="Transparent" }
  AlphaToMask On
  ZTest Less
  ZWrite Off
  Stencil {
   Ref 2
   ReadMask 1
   WriteMask 3
   Pass Replace
   ZFail Replace
  }
  Blend SrcAlpha OneMinusSrcAlpha
  ColorMask RGB
  Offset 1, 1
  GpuProgramID 11407
Program "vp" {
SubProgram "opengl " {
// Stats: 155 math, 9 textures, 3 branches
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" }
"#version 120

#ifdef VERTEX
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _ScreenParams;
uniform vec4 unity_SHBr;
uniform vec4 unity_SHBg;
uniform vec4 unity_SHBb;
uniform vec4 unity_SHC;

uniform mat4 _Object2World;
uniform mat4 _World2Object;
uniform vec4 unity_WorldTransformParams;

uniform vec4 unity_ColorSpaceLuminance;
uniform float _FaceDilate;
uniform mat4 _EnvMatrix;
uniform float _WeightNormal;
uniform float _WeightBold;
uniform float _ScaleRatioA;
uniform float _VertexOffsetX;
uniform float _VertexOffsetY;
uniform float _GradientScale;
uniform float _ScaleX;
uniform float _ScaleY;
uniform float _PerspectiveFilter;
uniform vec4 _MainTex_ST;
uniform vec4 _FaceTex_ST;
attribute vec4 TANGENT;
varying vec4 xlv_TEXCOORD0;
varying vec4 xlv_TEXCOORD1;
varying vec4 xlv_TEXCOORD2;
varying vec4 xlv_TEXCOORD3;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD4;
varying vec3 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec4 tmpvar_1;
  vec4 tmpvar_2;
  vec3 tmpvar_3;
  vec3 tmpvar_4;
  vec4 tmpvar_5;
  vec3 tmpvar_6;
  tmpvar_5.zw = gl_Vertex.zw;
  vec2 tmpvar_7;
  float scale_8;
  vec2 pixelSize_9;
  tmpvar_5.x = (gl_Vertex.x + _VertexOffsetX);
  tmpvar_5.y = (gl_Vertex.y + _VertexOffsetY);
  vec4 tmpvar_10;
  tmpvar_10.w = 1.0;
  tmpvar_10.xyz = _WorldSpaceCameraPos;
  tmpvar_6 = (gl_Normal * sign(dot (gl_Normal, 
    ((_World2Object * tmpvar_10).xyz - tmpvar_5.xyz)
  )));
  vec2 tmpvar_11;
  tmpvar_11.x = _ScaleX;
  tmpvar_11.y = _ScaleY;
  mat2 tmpvar_12;
  tmpvar_12[0] = gl_ProjectionMatrix[0].xy;
  tmpvar_12[1] = gl_ProjectionMatrix[1].xy;
  pixelSize_9 = ((gl_ModelViewProjectionMatrix * tmpvar_5).ww / (tmpvar_11 * (tmpvar_12 * _ScreenParams.xy)));
  scale_8 = (inversesqrt(dot (pixelSize_9, pixelSize_9)) * ((
    abs(gl_MultiTexCoord1.y)
   * _GradientScale) * 1.5));
  vec4 v_13;
  float tmpvar_14;
  tmpvar_14 = _World2Object[0].x;
  v_13.x = tmpvar_14;
  float tmpvar_15;
  tmpvar_15 = _World2Object[1].x;
  v_13.y = tmpvar_15;
  float tmpvar_16;
  tmpvar_16 = _World2Object[2].x;
  v_13.z = tmpvar_16;
  float tmpvar_17;
  tmpvar_17 = _World2Object[3].x;
  v_13.w = tmpvar_17;
  vec4 v_18;
  float tmpvar_19;
  tmpvar_19 = _World2Object[0].y;
  v_18.x = tmpvar_19;
  float tmpvar_20;
  tmpvar_20 = _World2Object[1].y;
  v_18.y = tmpvar_20;
  float tmpvar_21;
  tmpvar_21 = _World2Object[2].y;
  v_18.z = tmpvar_21;
  float tmpvar_22;
  tmpvar_22 = _World2Object[3].y;
  v_18.w = tmpvar_22;
  vec4 v_23;
  float tmpvar_24;
  tmpvar_24 = _World2Object[0].z;
  v_23.x = tmpvar_24;
  float tmpvar_25;
  tmpvar_25 = _World2Object[1].z;
  v_23.y = tmpvar_25;
  float tmpvar_26;
  tmpvar_26 = _World2Object[2].z;
  v_23.z = tmpvar_26;
  float tmpvar_27;
  tmpvar_27 = _World2Object[3].z;
  v_23.w = tmpvar_27;
  float tmpvar_28;
  tmpvar_28 = mix ((scale_8 * (1.0 - _PerspectiveFilter)), scale_8, abs(dot (
    normalize((((v_13.xyz * tmpvar_6.x) + (v_18.xyz * tmpvar_6.y)) + (v_23.xyz * tmpvar_6.z)))
  , 
    normalize((_WorldSpaceCameraPos - (_Object2World * tmpvar_5).xyz))
  )));
  scale_8 = tmpvar_28;
  tmpvar_7.y = tmpvar_28;
  tmpvar_7.x = ((mix (_WeightNormal, _WeightBold, 
    float((0.0 >= gl_MultiTexCoord1.y))
  ) / _GradientScale) + ((_FaceDilate * _ScaleRatioA) * 0.5));
  vec2 tmpvar_29;
  tmpvar_29.x = ((floor(gl_MultiTexCoord1.x) * 5.0) / 4096.0);
  tmpvar_29.y = (fract(gl_MultiTexCoord1.x) * 5.0);
  mat3 tmpvar_30;
  tmpvar_30[0] = _EnvMatrix[0].xyz;
  tmpvar_30[1] = _EnvMatrix[1].xyz;
  tmpvar_30[2] = _EnvMatrix[2].xyz;
  tmpvar_3 = (tmpvar_30 * (_WorldSpaceCameraPos - (_Object2World * tmpvar_5).xyz));
  tmpvar_1 = (gl_ModelViewProjectionMatrix * tmpvar_5);
  tmpvar_2.xy = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  tmpvar_2.zw = ((tmpvar_29 * _FaceTex_ST.xy) + _FaceTex_ST.zw);
  vec3 tmpvar_31;
  tmpvar_31 = (_Object2World * tmpvar_5).xyz;
  vec4 v_32;
  v_32.x = tmpvar_14;
  v_32.y = tmpvar_15;
  v_32.z = tmpvar_16;
  v_32.w = tmpvar_17;
  vec4 v_33;
  v_33.x = tmpvar_19;
  v_33.y = tmpvar_20;
  v_33.z = tmpvar_21;
  v_33.w = tmpvar_22;
  vec4 v_34;
  v_34.x = tmpvar_24;
  v_34.y = tmpvar_25;
  v_34.z = tmpvar_26;
  v_34.w = tmpvar_27;
  vec3 tmpvar_35;
  tmpvar_35 = normalize(((
    (v_32.xyz * tmpvar_6.x)
   + 
    (v_33.xyz * tmpvar_6.y)
  ) + (v_34.xyz * tmpvar_6.z)));
  mat3 tmpvar_36;
  tmpvar_36[0] = _Object2World[0].xyz;
  tmpvar_36[1] = _Object2World[1].xyz;
  tmpvar_36[2] = _Object2World[2].xyz;
  vec3 tmpvar_37;
  tmpvar_37 = normalize((tmpvar_36 * TANGENT.xyz));
  vec3 tmpvar_38;
  tmpvar_38 = (((tmpvar_35.yzx * tmpvar_37.zxy) - (tmpvar_35.zxy * tmpvar_37.yzx)) * (TANGENT.w * unity_WorldTransformParams.w));
  vec4 tmpvar_39;
  tmpvar_39.x = tmpvar_37.x;
  tmpvar_39.y = tmpvar_38.x;
  tmpvar_39.z = tmpvar_35.x;
  tmpvar_39.w = tmpvar_31.x;
  vec4 tmpvar_40;
  tmpvar_40.x = tmpvar_37.y;
  tmpvar_40.y = tmpvar_38.y;
  tmpvar_40.z = tmpvar_35.y;
  tmpvar_40.w = tmpvar_31.y;
  vec4 tmpvar_41;
  tmpvar_41.x = tmpvar_37.z;
  tmpvar_41.y = tmpvar_38.z;
  tmpvar_41.z = tmpvar_35.z;
  tmpvar_41.w = tmpvar_31.z;
  tmpvar_4 = vec3(0.0, 0.0, 0.0);
  vec3 ambient_42;
  ambient_42 = tmpvar_4;
  if ((unity_ColorSpaceLuminance.w == 0.0)) {
    ambient_42 = vec3(0.0, 0.0, 0.0);
  };
  vec3 x1_43;
  vec4 tmpvar_44;
  tmpvar_44 = (tmpvar_35.xyzz * tmpvar_35.yzzx);
  x1_43.x = dot (unity_SHBr, tmpvar_44);
  x1_43.y = dot (unity_SHBg, tmpvar_44);
  x1_43.z = dot (unity_SHBb, tmpvar_44);
  ambient_42 = (ambient_42 + (x1_43 + (unity_SHC.xyz * 
    ((tmpvar_35.x * tmpvar_35.x) - (tmpvar_35.y * tmpvar_35.y))
  )));
  tmpvar_4 = ambient_42;
  gl_Position = tmpvar_1;
  xlv_TEXCOORD0 = tmpvar_2;
  xlv_TEXCOORD1 = tmpvar_39;
  xlv_TEXCOORD2 = tmpvar_40;
  xlv_TEXCOORD3 = tmpvar_41;
  xlv_COLOR0 = gl_Color;
  xlv_TEXCOORD4 = tmpvar_7;
  xlv_TEXCOORD5 = tmpvar_3;
  xlv_TEXCOORD6 = ambient_42;
}


#endif
#ifdef FRAGMENT
uniform vec4 _Time;
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _WorldSpaceLightPos0;
uniform vec4 unity_SHAr;
uniform vec4 unity_SHAg;
uniform vec4 unity_SHAb;
uniform mat4 _Object2World;
uniform vec4 unity_ColorSpaceLuminance;
uniform vec4 _LightColor0;
uniform vec4 _SpecColor;
uniform sampler2D _FaceTex;
uniform float _FaceUVSpeedX;
uniform float _FaceUVSpeedY;
uniform vec4 _FaceColor;
uniform float _OutlineSoftness;
uniform sampler2D _OutlineTex;
uniform float _OutlineUVSpeedX;
uniform float _OutlineUVSpeedY;
uniform vec4 _OutlineColor;
uniform float _OutlineWidth;
uniform float _Bevel;
uniform float _BevelOffset;
uniform float _BevelWidth;
uniform float _BevelClamp;
uniform float _BevelRoundness;
uniform sampler2D _BumpMap;
uniform float _BumpOutline;
uniform float _BumpFace;
uniform samplerCube _Cube;
uniform vec4 _ReflectFaceColor;
uniform vec4 _ReflectOutlineColor;
uniform float _ShaderFlags;
uniform float _ScaleRatioA;
uniform sampler2D _MainTex;
uniform float _TextureWidth;
uniform float _TextureHeight;
uniform float _GradientScale;
uniform float _FaceShininess;
uniform float _OutlineShininess;
varying vec4 xlv_TEXCOORD0;
varying vec4 xlv_TEXCOORD1;
varying vec4 xlv_TEXCOORD2;
varying vec4 xlv_TEXCOORD3;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD4;
varying vec3 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec3 worldN_1;
  vec4 c_2;
  vec3 tmpvar_3;
  vec3 tmpvar_4;
  float tmpvar_5;
  float tmpvar_6;
  vec3 tmpvar_7;
  tmpvar_7.x = xlv_TEXCOORD1.w;
  tmpvar_7.y = xlv_TEXCOORD2.w;
  tmpvar_7.z = xlv_TEXCOORD3.w;
  vec3 tmpvar_8;
  tmpvar_8 = normalize((_WorldSpaceCameraPos - tmpvar_7));
  tmpvar_3 = vec3(0.0, 0.0, 0.0);
  tmpvar_6 = 0.0;
  tmpvar_5 = 0.0;
  vec3 tmpvar_9;
  vec3 tmpvar_10;
  float tmpvar_11;
  float tmpvar_12;
  tmpvar_9 = tmpvar_3;
  tmpvar_10 = tmpvar_4;
  tmpvar_11 = tmpvar_5;
  tmpvar_12 = tmpvar_6;
  vec3 bump_13;
  vec4 outlineColor_14;
  vec4 faceColor_15;
  vec3 tmpvar_16;
  tmpvar_16.z = 0.0;
  tmpvar_16.x = (1.0/(_TextureWidth));
  tmpvar_16.y = (1.0/(_TextureHeight));
  vec4 tmpvar_17;
  tmpvar_17.x = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.xz)).w;
  tmpvar_17.y = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.xz)).w;
  tmpvar_17.z = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.zy)).w;
  tmpvar_17.w = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.zy)).w;
  float tmpvar_18;
  tmpvar_18 = (((
    (0.5 - texture2D (_MainTex, xlv_TEXCOORD0.xy).w)
   - xlv_TEXCOORD4.x) * xlv_TEXCOORD4.y) + 0.5);
  float tmpvar_19;
  tmpvar_19 = ((_OutlineWidth * _ScaleRatioA) * xlv_TEXCOORD4.y);
  float tmpvar_20;
  tmpvar_20 = ((_OutlineSoftness * _ScaleRatioA) * xlv_TEXCOORD4.y);
  outlineColor_14.xyz = _OutlineColor.xyz;
  faceColor_15 = (_FaceColor * xlv_COLOR0);
  outlineColor_14.w = (_OutlineColor.w * xlv_COLOR0.w);
  vec2 tmpvar_21;
  tmpvar_21.x = (xlv_TEXCOORD0.z + (_FaceUVSpeedX * _Time.y));
  tmpvar_21.y = (xlv_TEXCOORD0.w + (_FaceUVSpeedY * _Time.y));
  faceColor_15 = (faceColor_15 * texture2D (_FaceTex, tmpvar_21));
  vec2 tmpvar_22;
  tmpvar_22.x = (xlv_TEXCOORD0.z + (_OutlineUVSpeedX * _Time.y));
  tmpvar_22.y = (xlv_TEXCOORD0.w + (_OutlineUVSpeedY * _Time.y));
  outlineColor_14 = (outlineColor_14 * texture2D (_OutlineTex, tmpvar_22));
  vec4 faceColor_23;
  faceColor_23.w = faceColor_15.w;
  vec4 outlineColor_24;
  outlineColor_24.w = outlineColor_14.w;
  faceColor_23.xyz = (faceColor_15.xyz * faceColor_15.w);
  outlineColor_24.xyz = (outlineColor_14.xyz * outlineColor_14.w);
  faceColor_23 = (mix (faceColor_23, outlineColor_24, vec4((
    clamp ((tmpvar_18 + (tmpvar_19 * 0.5)), 0.0, 1.0)
   * 
    sqrt(min (1.0, tmpvar_19))
  ))) * (1.0 - clamp (
    (((tmpvar_18 - (tmpvar_19 * 0.5)) + (tmpvar_20 * 0.5)) / (1.0 + tmpvar_20))
  , 0.0, 1.0)));
  faceColor_15.w = faceColor_23.w;
  faceColor_15.xyz = (faceColor_23.xyz / max (faceColor_23.w, 0.0001));
  vec4 h_25;
  h_25 = tmpvar_17;
  float tmpvar_26;
  tmpvar_26 = (_ShaderFlags / 2.0);
  float tmpvar_27;
  tmpvar_27 = (fract(abs(tmpvar_26)) * 2.0);
  float tmpvar_28;
  if ((tmpvar_26 >= 0.0)) {
    tmpvar_28 = tmpvar_27;
  } else {
    tmpvar_28 = -(tmpvar_27);
  };
  h_25 = (tmpvar_17 + (xlv_TEXCOORD4.x + _BevelOffset));
  float tmpvar_29;
  tmpvar_29 = max (0.01, (_OutlineWidth + _BevelWidth));
  h_25 = (h_25 - 0.5);
  h_25 = (h_25 / tmpvar_29);
  vec4 tmpvar_30;
  tmpvar_30 = clamp ((h_25 + 0.5), 0.0, 1.0);
  h_25 = tmpvar_30;
  if (bool(float((tmpvar_28 >= 1.0)))) {
    h_25 = (1.0 - abs((
      (tmpvar_30 * 2.0)
     - 1.0)));
  };
  h_25 = (min (mix (h_25, 
    sin(((h_25 * 3.141592) / 2.0))
  , vec4(_BevelRoundness)), vec4((1.0 - _BevelClamp))) * ((_Bevel * tmpvar_29) * (_GradientScale * -2.0)));
  vec3 tmpvar_31;
  tmpvar_31.xy = vec2(1.0, 0.0);
  tmpvar_31.z = (h_25.y - h_25.x);
  vec3 tmpvar_32;
  tmpvar_32 = normalize(tmpvar_31);
  vec3 tmpvar_33;
  tmpvar_33.xy = vec2(0.0, -1.0);
  tmpvar_33.z = (h_25.w - h_25.z);
  vec3 tmpvar_34;
  tmpvar_34 = normalize(tmpvar_33);
  vec3 normal_35;
  normal_35.xy = ((texture2D (_BumpMap, xlv_TEXCOORD0.zw).wy * 2.0) - 1.0);
  normal_35.z = sqrt((1.0 - clamp (
    dot (normal_35.xy, normal_35.xy)
  , 0.0, 1.0)));
  bump_13 = (normal_35 * mix (_BumpFace, _BumpOutline, clamp (
    (tmpvar_18 + (tmpvar_19 * 0.5))
  , 0.0, 1.0)));
  vec3 tmpvar_36;
  tmpvar_36 = mix (vec3(0.0, 0.0, 1.0), bump_13, faceColor_23.www);
  bump_13 = tmpvar_36;
  vec3 tmpvar_37;
  tmpvar_37 = normalize(((
    (tmpvar_32.yzx * tmpvar_34.zxy)
   - 
    (tmpvar_32.zxy * tmpvar_34.yzx)
  ) - tmpvar_36));
  mat3 tmpvar_38;
  tmpvar_38[0] = _Object2World[0].xyz;
  tmpvar_38[1] = _Object2World[1].xyz;
  tmpvar_38[2] = _Object2World[2].xyz;
  vec3 N_39;
  N_39 = (tmpvar_38 * tmpvar_37);
  vec3 tmpvar_40;
  tmpvar_40 = ((textureCube (_Cube, (xlv_TEXCOORD5 - 
    (2.0 * (dot (N_39, xlv_TEXCOORD5) * N_39))
  )).xyz * mix (_ReflectFaceColor.xyz, _ReflectOutlineColor.xyz, vec3(
    clamp ((tmpvar_18 + (tmpvar_19 * 0.5)), 0.0, 1.0)
  ))) * faceColor_23.w);
  tmpvar_9 = faceColor_15.xyz;
  tmpvar_10 = -(tmpvar_37);
  float tmpvar_41;
  tmpvar_41 = mix (_FaceShininess, _OutlineShininess, clamp ((tmpvar_18 + 
    (tmpvar_19 * 0.5)
  ), 0.0, 1.0));
  tmpvar_11 = 1.0;
  tmpvar_12 = faceColor_15.w;
  tmpvar_3 = tmpvar_9;
  tmpvar_5 = tmpvar_11;
  tmpvar_6 = tmpvar_12;
  c_2 = vec4(0.0, 0.0, 0.0, 0.0);
  worldN_1.x = dot (xlv_TEXCOORD1.xyz, tmpvar_10);
  worldN_1.y = dot (xlv_TEXCOORD2.xyz, tmpvar_10);
  worldN_1.z = dot (xlv_TEXCOORD3.xyz, tmpvar_10);
  tmpvar_4 = worldN_1;
  vec3 ambient_42;
  vec4 tmpvar_43;
  tmpvar_43.w = 1.0;
  tmpvar_43.xyz = worldN_1;
  vec3 x_44;
  x_44.x = dot (unity_SHAr, tmpvar_43);
  x_44.y = dot (unity_SHAg, tmpvar_43);
  x_44.z = dot (unity_SHAb, tmpvar_43);
  vec3 tmpvar_45;
  tmpvar_45 = max (vec3(0.0, 0.0, 0.0), (xlv_TEXCOORD6 + x_44));
  ambient_42 = tmpvar_45;
  if ((unity_ColorSpaceLuminance.w == 0.0)) {
    ambient_42 = max (((1.055 * 
      pow (max (tmpvar_45, vec3(0.0, 0.0, 0.0)), vec3(0.4166667, 0.4166667, 0.4166667))
    ) - 0.055), vec3(0.0, 0.0, 0.0));
  };
  vec4 c_46;
  vec4 c_47;
  c_47.xyz = (((faceColor_15.xyz * _LightColor0.xyz) * max (0.0, 
    dot (worldN_1, _WorldSpaceLightPos0.xyz)
  )) + ((_LightColor0.xyz * _SpecColor.xyz) * pow (
    max (0.0, dot (worldN_1, normalize((_WorldSpaceLightPos0.xyz + tmpvar_8))))
  , 
    (tmpvar_41 * 128.0)
  )));
  c_47.w = tmpvar_12;
  c_46.w = c_47.w;
  c_46.xyz = (c_47.xyz + (faceColor_15.xyz * ambient_42));
  c_2.w = c_46.w;
  c_2.xyz = (c_46.xyz + tmpvar_40);
  gl_FragData[0] = c_2;
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 103 math
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
Matrix 10 [_EnvMatrix] 3
Matrix 4 [_Object2World] 3
Matrix 7 [_World2Object] 3
Matrix 0 [glstate_matrix_mvp]
Matrix 13 [glstate_matrix_projection] 2
Float 22 [_FaceDilate]
Vector 33 [_FaceTex_ST]
Float 28 [_GradientScale]
Vector 32 [_MainTex_ST]
Float 31 [_PerspectiveFilter]
Float 25 [_ScaleRatioA]
Float 29 [_ScaleX]
Float 30 [_ScaleY]
Vector 16 [_ScreenParams]
Float 26 [_VertexOffsetX]
Float 27 [_VertexOffsetY]
Float 24 [_WeightBold]
Float 23 [_WeightNormal]
Vector 15 [_WorldSpaceCameraPos]
Vector 19 [unity_SHBb]
Vector 18 [unity_SHBg]
Vector 17 [unity_SHBr]
Vector 20 [unity_SHC]
Vector 21 [unity_WorldTransformParams]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   row_major float4x4 _EnvMatrix;
//   float _FaceDilate;
//   float4 _FaceTex_ST;
//   float _GradientScale;
//   float4 _MainTex_ST;
//   row_major float4x4 _Object2World;
//   float _PerspectiveFilter;
//   float _ScaleRatioA;
//   float _ScaleX;
//   float _ScaleY;
//   float4 _ScreenParams;
//   float _VertexOffsetX;
//   float _VertexOffsetY;
//   float _WeightBold;
//   float _WeightNormal;
//   row_major float4x4 _World2Object;
//   float3 _WorldSpaceCameraPos;
//   row_major float4x4 glstate_matrix_mvp;
//   row_major float4x4 glstate_matrix_projection;
//   float4 unity_SHBb;
//   float4 unity_SHBg;
//   float4 unity_SHBr;
//   float4 unity_SHC;
//   float4 unity_WorldTransformParams;
//
//
// Registers:
//
//   Name                       Reg   Size
//   -------------------------- ----- ----
//   glstate_matrix_mvp         c0       4
//   _Object2World              c4       3
//   _World2Object              c7       3
//   _EnvMatrix                 c10      3
//   glstate_matrix_projection  c13      2
//   _WorldSpaceCameraPos       c15      1
//   _ScreenParams              c16      1
//   unity_SHBr                 c17      1
//   unity_SHBg                 c18      1
//   unity_SHBb                 c19      1
//   unity_SHC                  c20      1
//   unity_WorldTransformParams c21      1
//   _FaceDilate                c22      1
//   _WeightNormal              c23      1
//   _WeightBold                c24      1
//   _ScaleRatioA               c25      1
//   _VertexOffsetX             c26      1
//   _VertexOffsetY             c27      1
//   _GradientScale             c28      1
//   _ScaleX                    c29      1
//   _ScaleY                    c30      1
//   _PerspectiveFilter         c31      1
//   _MainTex_ST                c32      1
//   _FaceTex_ST                c33      1
//

    vs_3_0
    def c34, 0, 1, 1.5, 0.5
    def c35, 0.00122070313, 5, 0, 0
    dcl_position v0
    dcl_tangent v1
    dcl_normal v2
    dcl_texcoord v3
    dcl_texcoord1 v4
    dcl_color v5
    dcl_position o0
    dcl_texcoord o1
    dcl_texcoord1 o2
    dcl_texcoord2 o3
    dcl_texcoord3 o4
    dcl_color o5
    dcl_texcoord4 o6.xy
    dcl_texcoord5 o7.xyz
    dcl_texcoord6 o8.xyz
    mov r0.xy, c34
    mad r1, c15.xyzx, r0.yyyx, r0.xxxy
    dp4 r2.x, c7, r1
    dp4 r2.y, c8, r1
    dp4 r2.z, c9, r1
    add r1.x, c26.x, v0.x
    add r1.y, c27.x, v0.y
    mov r1.zw, v0
    add r0.xzw, -r1.xyyz, r2.xyyz
    dp3 r0.x, v2, r0.xzww
    slt r0.z, -r0.x, r0.x
    slt r0.x, r0.x, -r0.x
    add r0.x, -r0.x, r0.z
    mul r0.xzw, r0.x, v2.xyyz
    mul r2, r0.z, c8.xyzz
    mad r2, c7.xyzz, r0.x, r2
    mad r2, c9.xyzz, r0.w, r2
    dp3 r0.x, r2.xyww, r2.xyww
    rsq r0.x, r0.x
    mul r2, r0.x, r2
    dp4 r3.x, c4, r1
    dp4 r3.y, c5, r1
    dp4 r3.z, c6, r1
    add r0.xzw, -r3.xyyz, c15.xyyz
    mov o2.w, r3.x
    mov o3.w, r3.y
    mov o4.w, r3.z
    nrm r3.xyz, r0.xzww
    dp3 r3.x, r2.xyww, r3
    mov r4.xy, c16
    mul r3.yz, r4.xxyw, c13.xxyw
    add r3.y, r3.z, r3.y
    mul r3.y, r3.y, c29.x
    rcp r5.x, r3.y
    mul r3.yz, r4.xxyw, c14.xxyw
    add r3.y, r3.z, r3.y
    mul r3.y, r3.y, c30.x
    rcp r5.y, r3.y
    dp4 r3.y, c3, r1
    mul r3.zw, r5.xyxy, r3.y
    mov o0.w, r3.y
    mul r3.yz, r3.xzww, r3.xzww
    add r3.y, r3.z, r3.y
    rsq r3.y, r3.y
    mul r3.z, c28.x, v4_abs.y
    mul r3.y, r3.y, r3.z
    mul r3.z, r3.y, c34.z
    add r0.y, r0.y, -c31.x
    mul r0.y, r0.y, r3.z
    mad r3.y, r3.y, c34.z, -r0.y
    mad o6.y, r3_abs.x, r3.y, r0.y
    sge r0.y, c34.x, v4.y
    mov r3.x, c23.x
    add r3.x, -r3.x, c24.x
    mad r0.y, r0.y, r3.x, c23.x
    mov r3.x, c22.x
    mul r3.x, r3.x, c25.x
    mul r3.x, r3.x, c34.w
    rcp r3.y, c28.x
    mad o6.x, r0.y, r3.y, r3.x
    dp3 o7.x, c10, r0.xzww
    dp3 o7.y, c11, r0.xzww
    dp3 o7.z, c12, r0.xzww
    dp4 o0.x, c0, r1
    dp4 o0.y, c1, r1
    dp4 o0.z, c2, r1
    mad o1.xy, v3, c32, c32.zwzw
    frc r0.x, v4.x
    add r0.y, -r0.x, v4.x
    mul r0.zw, r0.xyyx, c33.xyxy
    mov r1.zw, c33
    mad o1.zw, r0, c35.xyxy, r1
    mul r0.x, r2.y, r2.y
    mad r0.x, r2.x, r2.x, -r0.x
    mul r1, r2.ywzx, r2
    dp4 r3.x, c17, r1
    dp4 r3.y, c18, r1
    dp4 r3.z, c19, r1
    mad o8.xyz, c20, r0.x, r3
    dp3 r0.z, c4, v1
    dp3 r0.x, c5, v1
    dp3 r0.y, c6, v1
    dp3 r0.w, r0, r0
    rsq r0.w, r0.w
    mul r0.xyz, r0.w, r0
    mov o2.x, r0.z
    mul r1.xyz, r0, r2.wxyw
    mad r1.xyz, r2.ywxw, r0.yzxw, -r1
    mul r0.z, c21.w, v1.w
    mul r1.xyz, r0.z, r1
    mov o2.y, r1.x
    mov o2.z, r2.x
    mov o3.x, r0.x
    mov o4.x, r0.y
    mov o3.y, r1.y
    mov o4.y, r1.z
    mov o3.z, r2.y
    mov o4.z, r2.w
    mov o5, v5

// approximately 101 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 80 math
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
ConstBuffer "$Globals" 592
Matrix 272 [_EnvMatrix]
Float 160 [_FaceDilate]
Float 452 [_WeightNormal]
Float 456 [_WeightBold]
Float 460 [_ScaleRatioA]
Float 472 [_VertexOffsetX]
Float 476 [_VertexOffsetY]
Float 528 [_GradientScale]
Float 532 [_ScaleX]
Float 536 [_ScaleY]
Float 540 [_PerspectiveFilter]
Vector 560 [_MainTex_ST]
Vector 576 [_FaceTex_ST]
ConstBuffer "UnityPerCamera" 144
Vector 64 [_WorldSpaceCameraPos] 3
Vector 96 [_ScreenParams]
ConstBuffer "UnityLighting" 720
Vector 656 [unity_SHBr]
Vector 672 [unity_SHBg]
Vector 688 [unity_SHBb]
Vector 704 [unity_SHC]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
Matrix 256 [_World2Object]
Vector 336 [unity_WorldTransformParams]
ConstBuffer "UnityPerFrame" 256
Matrix 0 [glstate_matrix_projection]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityLighting" 2
BindCB  "UnityPerDraw" 3
BindCB  "UnityPerFrame" 4
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// TANGENT                  0   xyzw        1     NONE   float   xyzw
// NORMAL                   0   xyz         2     NONE   float   xyz 
// TEXCOORD                 0   xyzw        3     NONE   float   xy  
// TEXCOORD                 1   xyzw        4     NONE   float   xy  
// TEXCOORD                 2   xyzw        5     NONE   float       
// TEXCOORD                 3   xyzw        6     NONE   float       
// COLOR                    0   xyzw        7     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyzw        2     NONE   float   xyzw
// TEXCOORD                 2   xyzw        3     NONE   float   xyzw
// TEXCOORD                 3   xyzw        4     NONE   float   xyzw
// COLOR                    0   xyzw        5     NONE   float   xyzw
// TEXCOORD                 4   xy          6     NONE   float   xy  
// TEXCOORD                 5   xyz         7     NONE   float   xyz 
// TEXCOORD                 6   xyz         8     NONE   float   xyz 
//
      vs_4_0
      dcl_constantbuffer cb0[37], immediateIndexed
      dcl_constantbuffer cb1[7], immediateIndexed
      dcl_constantbuffer cb2[45], immediateIndexed
      dcl_constantbuffer cb3[22], immediateIndexed
      dcl_constantbuffer cb4[2], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v1.xyzw
      dcl_input v2.xyz
      dcl_input v3.xy
      dcl_input v4.xy
      dcl_input v7.xyzw
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xyzw
      dcl_output o2.xyzw
      dcl_output o3.xyzw
      dcl_output o4.xyzw
      dcl_output o5.xyzw
      dcl_output o6.xy
      dcl_output o7.xyz
      dcl_output o8.xyz
      dcl_temps 5
   0: add r0.xy, v0.xyxx, cb0[29].zwzz
   1: mul r1.xyzw, r0.yyyy, cb3[1].xyzw
   2: mad r1.xyzw, cb3[0].xyzw, r0.xxxx, r1.xyzw
   3: mad r1.xyzw, cb3[2].xyzw, v0.zzzz, r1.xyzw
   4: mad o0.xyzw, cb3[3].xyzw, v0.wwww, r1.xyzw
   5: round_ni r0.w, v4.x
   6: mul r1.z, r0.w, cb0[36].x
   7: frc r0.w, v4.x
   8: mul r1.w, r0.w, cb0[36].y
   9: mad o1.zw, r1.zzzw, l(0.000000, 0.000000, 0.001221, 5.000000), cb0[36].zzzw
  10: mad o1.xy, v3.xyxx, cb0[35].xyxx, cb0[35].zwzz
  11: mul r1.xyz, cb1[4].yyyy, cb3[17].xyzx
  12: mad r1.xyz, cb3[16].xyzx, cb1[4].xxxx, r1.xyzx
  13: mad r1.xyz, cb3[18].xyzx, cb1[4].zzzz, r1.xyzx
  14: add r1.xyz, r1.xyzx, cb3[19].xyzx
  15: mov r0.z, v0.z
  16: add r1.xyz, -r0.xyzx, r1.xyzx
  17: dp3 r0.z, v2.xyzx, r1.xyzx
  18: lt r0.w, l(0.000000), r0.z
  19: lt r0.z, r0.z, l(0.000000)
  20: iadd r0.z, -r0.w, r0.z
  21: itof r0.z, r0.z
  22: mul r1.xyz, r0.zzzz, v2.xyzx
  23: mov r2.x, cb3[16].y
  24: mov r2.y, cb3[17].y
  25: mov r2.zw, cb3[18].yyyy
  26: mul r2.xyzw, r1.yyyy, r2.xyzw
  27: mov r3.x, cb3[16].x
  28: mov r3.y, cb3[17].x
  29: mov r3.zw, cb3[18].xxxx
  30: mad r2.xyzw, r3.xyzw, r1.xxxx, r2.xyzw
  31: mov r3.x, cb3[16].z
  32: mov r3.y, cb3[17].z
  33: mov r3.zw, cb3[18].zzzz
  34: mad r1.xyzw, r3.xyzw, r1.zzzz, r2.xyzw
  35: dp3 r0.z, r1.xywx, r1.xywx
  36: rsq r0.z, r0.z
  37: mul r1.xyzw, r0.zzzz, r1.xyzw
  38: mul r2.xyz, v1.yyyy, cb3[13].yzxy
  39: mad r2.xyz, cb3[12].yzxy, v1.xxxx, r2.xyzx
  40: mad r2.xyz, cb3[14].yzxy, v1.zzzz, r2.xyzx
  41: dp3 r0.z, r2.xyzx, r2.xyzx
  42: rsq r0.z, r0.z
  43: mul r2.xyz, r0.zzzz, r2.xyzx
  44: mul r3.xyz, r1.wxyw, r2.xyzx
  45: mad r3.xyz, r1.ywxy, r2.yzxy, -r3.xyzx
  46: mul r0.z, v1.w, cb3[21].w
  47: mul r3.xyz, r0.zzzz, r3.xyzx
  48: mov o2.y, r3.x
  49: mov o2.z, r1.x
  50: mov o2.x, r2.z
  51: mul r4.xyz, r0.yyyy, cb3[13].xyzx
  52: mad r4.xyz, cb3[12].xyzx, r0.xxxx, r4.xyzx
  53: mad r4.xyz, cb3[14].xyzx, v0.zzzz, r4.xyzx
  54: mad r4.xyz, cb3[15].xyzx, v0.wwww, r4.xyzx
  55: mov o2.w, r4.x
  56: mov o3.x, r2.x
  57: mov o4.x, r2.y
  58: mov o3.z, r1.y
  59: mov o3.y, r3.y
  60: mov o4.y, r3.z
  61: mov o3.w, r4.y
  62: mov o4.z, r1.w
  63: mov o4.w, r4.z
  64: add r2.xyz, -r4.xyzx, cb1[4].xyzx
  65: mov o5.xyzw, v7.xyzw
  66: mul r0.y, r0.y, cb3[1].w
  67: mad r0.x, cb3[0].w, r0.x, r0.y
  68: mad r0.x, cb3[2].w, v0.z, r0.x
  69: mad r0.x, cb3[3].w, v0.w, r0.x
  70: mul r0.yz, cb1[6].yyyy, cb4[1].xxyx
  71: mad r0.yz, cb4[0].xxyx, cb1[6].xxxx, r0.yyzy
  72: mul r0.yz, r0.yyzy, cb0[33].yyzy
  73: div r0.xy, r0.xxxx, r0.yzyy
  74: dp2 r0.x, r0.xyxx, r0.xyxx
  75: rsq r0.x, r0.x
  76: mul r0.y, |v4.y|, cb0[33].x
  77: mul r0.x, r0.x, r0.y
  78: mul r0.y, r0.x, l(1.500000)
  79: add r0.z, -cb0[33].w, l(1.000000)
  80: mul r0.y, r0.z, r0.y
  81: mad r0.x, r0.x, l(1.500000), -r0.y
  82: dp3 r0.z, r2.xyzx, r2.xyzx
  83: rsq r0.z, r0.z
  84: mul r3.xyz, r0.zzzz, r2.xyzx
  85: dp3 r0.z, r1.xywx, r3.xyzx
  86: mad o6.y, |r0.z|, r0.x, r0.y
  87: ge r0.x, l(0.000000), v4.y
  88: and r0.x, r0.x, l(0x3f800000)
  89: add r0.y, -cb0[28].y, cb0[28].z
  90: mad r0.x, r0.x, r0.y, cb0[28].y
  91: div r0.x, r0.x, cb0[33].x
  92: mul r0.y, cb0[10].x, cb0[28].w
  93: mad o6.x, r0.y, l(0.500000), r0.x
  94: mul r0.xyz, r2.yyyy, cb0[18].xyzx
  95: mad r0.xyz, cb0[17].xyzx, r2.xxxx, r0.xyzx
  96: mad o7.xyz, cb0[19].xyzx, r2.zzzz, r0.xyzx
  97: mul r0.x, r1.y, r1.y
  98: mad r0.x, r1.x, r1.x, -r0.x
  99: mul r1.xyzw, r1.ywzx, r1.xyzw
 100: dp4 r2.x, cb2[41].xyzw, r1.xyzw
 101: dp4 r2.y, cb2[42].xyzw, r1.xyzw
 102: dp4 r2.z, cb2[43].xyzw, r1.xyzw
 103: mad o8.xyz, cb2[44].xyzx, r0.xxxx, r2.xyzx
 104: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
// Stats: 155 math, 9 textures, 3 branches
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" "VERTEXLIGHT_ON" }
"#version 120

#ifdef VERTEX
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _ScreenParams;
uniform vec4 unity_4LightPosX0;
uniform vec4 unity_4LightPosY0;
uniform vec4 unity_4LightPosZ0;
uniform vec4 unity_4LightAtten0;
uniform vec4 unity_LightColor[8];
uniform vec4 unity_SHBr;
uniform vec4 unity_SHBg;
uniform vec4 unity_SHBb;
uniform vec4 unity_SHC;

uniform mat4 _Object2World;
uniform mat4 _World2Object;
uniform vec4 unity_WorldTransformParams;

uniform vec4 unity_ColorSpaceLuminance;
uniform float _FaceDilate;
uniform mat4 _EnvMatrix;
uniform float _WeightNormal;
uniform float _WeightBold;
uniform float _ScaleRatioA;
uniform float _VertexOffsetX;
uniform float _VertexOffsetY;
uniform float _GradientScale;
uniform float _ScaleX;
uniform float _ScaleY;
uniform float _PerspectiveFilter;
uniform vec4 _MainTex_ST;
uniform vec4 _FaceTex_ST;
attribute vec4 TANGENT;
varying vec4 xlv_TEXCOORD0;
varying vec4 xlv_TEXCOORD1;
varying vec4 xlv_TEXCOORD2;
varying vec4 xlv_TEXCOORD3;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD4;
varying vec3 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec4 tmpvar_1;
  vec4 tmpvar_2;
  vec3 tmpvar_3;
  vec4 tmpvar_4;
  vec3 tmpvar_5;
  tmpvar_4.zw = gl_Vertex.zw;
  vec2 tmpvar_6;
  float scale_7;
  vec2 pixelSize_8;
  tmpvar_4.x = (gl_Vertex.x + _VertexOffsetX);
  tmpvar_4.y = (gl_Vertex.y + _VertexOffsetY);
  vec4 tmpvar_9;
  tmpvar_9.w = 1.0;
  tmpvar_9.xyz = _WorldSpaceCameraPos;
  tmpvar_5 = (gl_Normal * sign(dot (gl_Normal, 
    ((_World2Object * tmpvar_9).xyz - tmpvar_4.xyz)
  )));
  vec2 tmpvar_10;
  tmpvar_10.x = _ScaleX;
  tmpvar_10.y = _ScaleY;
  mat2 tmpvar_11;
  tmpvar_11[0] = gl_ProjectionMatrix[0].xy;
  tmpvar_11[1] = gl_ProjectionMatrix[1].xy;
  pixelSize_8 = ((gl_ModelViewProjectionMatrix * tmpvar_4).ww / (tmpvar_10 * (tmpvar_11 * _ScreenParams.xy)));
  scale_7 = (inversesqrt(dot (pixelSize_8, pixelSize_8)) * ((
    abs(gl_MultiTexCoord1.y)
   * _GradientScale) * 1.5));
  vec4 v_12;
  float tmpvar_13;
  tmpvar_13 = _World2Object[0].x;
  v_12.x = tmpvar_13;
  float tmpvar_14;
  tmpvar_14 = _World2Object[1].x;
  v_12.y = tmpvar_14;
  float tmpvar_15;
  tmpvar_15 = _World2Object[2].x;
  v_12.z = tmpvar_15;
  float tmpvar_16;
  tmpvar_16 = _World2Object[3].x;
  v_12.w = tmpvar_16;
  vec4 v_17;
  float tmpvar_18;
  tmpvar_18 = _World2Object[0].y;
  v_17.x = tmpvar_18;
  float tmpvar_19;
  tmpvar_19 = _World2Object[1].y;
  v_17.y = tmpvar_19;
  float tmpvar_20;
  tmpvar_20 = _World2Object[2].y;
  v_17.z = tmpvar_20;
  float tmpvar_21;
  tmpvar_21 = _World2Object[3].y;
  v_17.w = tmpvar_21;
  vec4 v_22;
  float tmpvar_23;
  tmpvar_23 = _World2Object[0].z;
  v_22.x = tmpvar_23;
  float tmpvar_24;
  tmpvar_24 = _World2Object[1].z;
  v_22.y = tmpvar_24;
  float tmpvar_25;
  tmpvar_25 = _World2Object[2].z;
  v_22.z = tmpvar_25;
  float tmpvar_26;
  tmpvar_26 = _World2Object[3].z;
  v_22.w = tmpvar_26;
  float tmpvar_27;
  tmpvar_27 = mix ((scale_7 * (1.0 - _PerspectiveFilter)), scale_7, abs(dot (
    normalize((((v_12.xyz * tmpvar_5.x) + (v_17.xyz * tmpvar_5.y)) + (v_22.xyz * tmpvar_5.z)))
  , 
    normalize((_WorldSpaceCameraPos - (_Object2World * tmpvar_4).xyz))
  )));
  scale_7 = tmpvar_27;
  tmpvar_6.y = tmpvar_27;
  tmpvar_6.x = ((mix (_WeightNormal, _WeightBold, 
    float((0.0 >= gl_MultiTexCoord1.y))
  ) / _GradientScale) + ((_FaceDilate * _ScaleRatioA) * 0.5));
  vec2 tmpvar_28;
  tmpvar_28.x = ((floor(gl_MultiTexCoord1.x) * 5.0) / 4096.0);
  tmpvar_28.y = (fract(gl_MultiTexCoord1.x) * 5.0);
  mat3 tmpvar_29;
  tmpvar_29[0] = _EnvMatrix[0].xyz;
  tmpvar_29[1] = _EnvMatrix[1].xyz;
  tmpvar_29[2] = _EnvMatrix[2].xyz;
  tmpvar_3 = (tmpvar_29 * (_WorldSpaceCameraPos - (_Object2World * tmpvar_4).xyz));
  tmpvar_1 = (gl_ModelViewProjectionMatrix * tmpvar_4);
  tmpvar_2.xy = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  tmpvar_2.zw = ((tmpvar_28 * _FaceTex_ST.xy) + _FaceTex_ST.zw);
  vec3 tmpvar_30;
  tmpvar_30 = (_Object2World * tmpvar_4).xyz;
  vec4 v_31;
  v_31.x = tmpvar_13;
  v_31.y = tmpvar_14;
  v_31.z = tmpvar_15;
  v_31.w = tmpvar_16;
  vec4 v_32;
  v_32.x = tmpvar_18;
  v_32.y = tmpvar_19;
  v_32.z = tmpvar_20;
  v_32.w = tmpvar_21;
  vec4 v_33;
  v_33.x = tmpvar_23;
  v_33.y = tmpvar_24;
  v_33.z = tmpvar_25;
  v_33.w = tmpvar_26;
  vec3 tmpvar_34;
  tmpvar_34 = normalize(((
    (v_31.xyz * tmpvar_5.x)
   + 
    (v_32.xyz * tmpvar_5.y)
  ) + (v_33.xyz * tmpvar_5.z)));
  mat3 tmpvar_35;
  tmpvar_35[0] = _Object2World[0].xyz;
  tmpvar_35[1] = _Object2World[1].xyz;
  tmpvar_35[2] = _Object2World[2].xyz;
  vec3 tmpvar_36;
  tmpvar_36 = normalize((tmpvar_35 * TANGENT.xyz));
  vec3 tmpvar_37;
  tmpvar_37 = (((tmpvar_34.yzx * tmpvar_36.zxy) - (tmpvar_34.zxy * tmpvar_36.yzx)) * (TANGENT.w * unity_WorldTransformParams.w));
  vec4 tmpvar_38;
  tmpvar_38.x = tmpvar_36.x;
  tmpvar_38.y = tmpvar_37.x;
  tmpvar_38.z = tmpvar_34.x;
  tmpvar_38.w = tmpvar_30.x;
  vec4 tmpvar_39;
  tmpvar_39.x = tmpvar_36.y;
  tmpvar_39.y = tmpvar_37.y;
  tmpvar_39.z = tmpvar_34.y;
  tmpvar_39.w = tmpvar_30.y;
  vec4 tmpvar_40;
  tmpvar_40.x = tmpvar_36.z;
  tmpvar_40.y = tmpvar_37.z;
  tmpvar_40.z = tmpvar_34.z;
  tmpvar_40.w = tmpvar_30.z;
  vec3 col_41;
  vec4 ndotl_42;
  vec4 lengthSq_43;
  vec4 tmpvar_44;
  tmpvar_44 = (unity_4LightPosX0 - tmpvar_30.x);
  vec4 tmpvar_45;
  tmpvar_45 = (unity_4LightPosY0 - tmpvar_30.y);
  vec4 tmpvar_46;
  tmpvar_46 = (unity_4LightPosZ0 - tmpvar_30.z);
  lengthSq_43 = (tmpvar_44 * tmpvar_44);
  lengthSq_43 = (lengthSq_43 + (tmpvar_45 * tmpvar_45));
  lengthSq_43 = (lengthSq_43 + (tmpvar_46 * tmpvar_46));
  ndotl_42 = (tmpvar_44 * tmpvar_34.x);
  ndotl_42 = (ndotl_42 + (tmpvar_45 * tmpvar_34.y));
  ndotl_42 = (ndotl_42 + (tmpvar_46 * tmpvar_34.z));
  vec4 tmpvar_47;
  tmpvar_47 = max (vec4(0.0, 0.0, 0.0, 0.0), (ndotl_42 * inversesqrt(lengthSq_43)));
  ndotl_42 = tmpvar_47;
  vec4 tmpvar_48;
  tmpvar_48 = (tmpvar_47 * (1.0/((1.0 + 
    (lengthSq_43 * unity_4LightAtten0)
  ))));
  col_41 = (unity_LightColor[0].xyz * tmpvar_48.x);
  col_41 = (col_41 + (unity_LightColor[1].xyz * tmpvar_48.y));
  col_41 = (col_41 + (unity_LightColor[2].xyz * tmpvar_48.z));
  col_41 = (col_41 + (unity_LightColor[3].xyz * tmpvar_48.w));
  vec3 ambient_49;
  ambient_49 = col_41;
  if ((unity_ColorSpaceLuminance.w == 0.0)) {
    ambient_49 = (col_41 * ((col_41 * 
      ((col_41 * 0.305306) + 0.6821711)
    ) + 0.01252288));
  };
  vec3 x1_50;
  vec4 tmpvar_51;
  tmpvar_51 = (tmpvar_34.xyzz * tmpvar_34.yzzx);
  x1_50.x = dot (unity_SHBr, tmpvar_51);
  x1_50.y = dot (unity_SHBg, tmpvar_51);
  x1_50.z = dot (unity_SHBb, tmpvar_51);
  ambient_49 = (ambient_49 + (x1_50 + (unity_SHC.xyz * 
    ((tmpvar_34.x * tmpvar_34.x) - (tmpvar_34.y * tmpvar_34.y))
  )));
  gl_Position = tmpvar_1;
  xlv_TEXCOORD0 = tmpvar_2;
  xlv_TEXCOORD1 = tmpvar_38;
  xlv_TEXCOORD2 = tmpvar_39;
  xlv_TEXCOORD3 = tmpvar_40;
  xlv_COLOR0 = gl_Color;
  xlv_TEXCOORD4 = tmpvar_6;
  xlv_TEXCOORD5 = tmpvar_3;
  xlv_TEXCOORD6 = ambient_49;
}


#endif
#ifdef FRAGMENT
uniform vec4 _Time;
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _WorldSpaceLightPos0;
uniform vec4 unity_SHAr;
uniform vec4 unity_SHAg;
uniform vec4 unity_SHAb;
uniform mat4 _Object2World;
uniform vec4 unity_ColorSpaceLuminance;
uniform vec4 _LightColor0;
uniform vec4 _SpecColor;
uniform sampler2D _FaceTex;
uniform float _FaceUVSpeedX;
uniform float _FaceUVSpeedY;
uniform vec4 _FaceColor;
uniform float _OutlineSoftness;
uniform sampler2D _OutlineTex;
uniform float _OutlineUVSpeedX;
uniform float _OutlineUVSpeedY;
uniform vec4 _OutlineColor;
uniform float _OutlineWidth;
uniform float _Bevel;
uniform float _BevelOffset;
uniform float _BevelWidth;
uniform float _BevelClamp;
uniform float _BevelRoundness;
uniform sampler2D _BumpMap;
uniform float _BumpOutline;
uniform float _BumpFace;
uniform samplerCube _Cube;
uniform vec4 _ReflectFaceColor;
uniform vec4 _ReflectOutlineColor;
uniform float _ShaderFlags;
uniform float _ScaleRatioA;
uniform sampler2D _MainTex;
uniform float _TextureWidth;
uniform float _TextureHeight;
uniform float _GradientScale;
uniform float _FaceShininess;
uniform float _OutlineShininess;
varying vec4 xlv_TEXCOORD0;
varying vec4 xlv_TEXCOORD1;
varying vec4 xlv_TEXCOORD2;
varying vec4 xlv_TEXCOORD3;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD4;
varying vec3 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec3 worldN_1;
  vec4 c_2;
  vec3 tmpvar_3;
  vec3 tmpvar_4;
  float tmpvar_5;
  float tmpvar_6;
  vec3 tmpvar_7;
  tmpvar_7.x = xlv_TEXCOORD1.w;
  tmpvar_7.y = xlv_TEXCOORD2.w;
  tmpvar_7.z = xlv_TEXCOORD3.w;
  vec3 tmpvar_8;
  tmpvar_8 = normalize((_WorldSpaceCameraPos - tmpvar_7));
  tmpvar_3 = vec3(0.0, 0.0, 0.0);
  tmpvar_6 = 0.0;
  tmpvar_5 = 0.0;
  vec3 tmpvar_9;
  vec3 tmpvar_10;
  float tmpvar_11;
  float tmpvar_12;
  tmpvar_9 = tmpvar_3;
  tmpvar_10 = tmpvar_4;
  tmpvar_11 = tmpvar_5;
  tmpvar_12 = tmpvar_6;
  vec3 bump_13;
  vec4 outlineColor_14;
  vec4 faceColor_15;
  vec3 tmpvar_16;
  tmpvar_16.z = 0.0;
  tmpvar_16.x = (1.0/(_TextureWidth));
  tmpvar_16.y = (1.0/(_TextureHeight));
  vec4 tmpvar_17;
  tmpvar_17.x = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.xz)).w;
  tmpvar_17.y = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.xz)).w;
  tmpvar_17.z = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.zy)).w;
  tmpvar_17.w = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.zy)).w;
  float tmpvar_18;
  tmpvar_18 = (((
    (0.5 - texture2D (_MainTex, xlv_TEXCOORD0.xy).w)
   - xlv_TEXCOORD4.x) * xlv_TEXCOORD4.y) + 0.5);
  float tmpvar_19;
  tmpvar_19 = ((_OutlineWidth * _ScaleRatioA) * xlv_TEXCOORD4.y);
  float tmpvar_20;
  tmpvar_20 = ((_OutlineSoftness * _ScaleRatioA) * xlv_TEXCOORD4.y);
  outlineColor_14.xyz = _OutlineColor.xyz;
  faceColor_15 = (_FaceColor * xlv_COLOR0);
  outlineColor_14.w = (_OutlineColor.w * xlv_COLOR0.w);
  vec2 tmpvar_21;
  tmpvar_21.x = (xlv_TEXCOORD0.z + (_FaceUVSpeedX * _Time.y));
  tmpvar_21.y = (xlv_TEXCOORD0.w + (_FaceUVSpeedY * _Time.y));
  faceColor_15 = (faceColor_15 * texture2D (_FaceTex, tmpvar_21));
  vec2 tmpvar_22;
  tmpvar_22.x = (xlv_TEXCOORD0.z + (_OutlineUVSpeedX * _Time.y));
  tmpvar_22.y = (xlv_TEXCOORD0.w + (_OutlineUVSpeedY * _Time.y));
  outlineColor_14 = (outlineColor_14 * texture2D (_OutlineTex, tmpvar_22));
  vec4 faceColor_23;
  faceColor_23.w = faceColor_15.w;
  vec4 outlineColor_24;
  outlineColor_24.w = outlineColor_14.w;
  faceColor_23.xyz = (faceColor_15.xyz * faceColor_15.w);
  outlineColor_24.xyz = (outlineColor_14.xyz * outlineColor_14.w);
  faceColor_23 = (mix (faceColor_23, outlineColor_24, vec4((
    clamp ((tmpvar_18 + (tmpvar_19 * 0.5)), 0.0, 1.0)
   * 
    sqrt(min (1.0, tmpvar_19))
  ))) * (1.0 - clamp (
    (((tmpvar_18 - (tmpvar_19 * 0.5)) + (tmpvar_20 * 0.5)) / (1.0 + tmpvar_20))
  , 0.0, 1.0)));
  faceColor_15.w = faceColor_23.w;
  faceColor_15.xyz = (faceColor_23.xyz / max (faceColor_23.w, 0.0001));
  vec4 h_25;
  h_25 = tmpvar_17;
  float tmpvar_26;
  tmpvar_26 = (_ShaderFlags / 2.0);
  float tmpvar_27;
  tmpvar_27 = (fract(abs(tmpvar_26)) * 2.0);
  float tmpvar_28;
  if ((tmpvar_26 >= 0.0)) {
    tmpvar_28 = tmpvar_27;
  } else {
    tmpvar_28 = -(tmpvar_27);
  };
  h_25 = (tmpvar_17 + (xlv_TEXCOORD4.x + _BevelOffset));
  float tmpvar_29;
  tmpvar_29 = max (0.01, (_OutlineWidth + _BevelWidth));
  h_25 = (h_25 - 0.5);
  h_25 = (h_25 / tmpvar_29);
  vec4 tmpvar_30;
  tmpvar_30 = clamp ((h_25 + 0.5), 0.0, 1.0);
  h_25 = tmpvar_30;
  if (bool(float((tmpvar_28 >= 1.0)))) {
    h_25 = (1.0 - abs((
      (tmpvar_30 * 2.0)
     - 1.0)));
  };
  h_25 = (min (mix (h_25, 
    sin(((h_25 * 3.141592) / 2.0))
  , vec4(_BevelRoundness)), vec4((1.0 - _BevelClamp))) * ((_Bevel * tmpvar_29) * (_GradientScale * -2.0)));
  vec3 tmpvar_31;
  tmpvar_31.xy = vec2(1.0, 0.0);
  tmpvar_31.z = (h_25.y - h_25.x);
  vec3 tmpvar_32;
  tmpvar_32 = normalize(tmpvar_31);
  vec3 tmpvar_33;
  tmpvar_33.xy = vec2(0.0, -1.0);
  tmpvar_33.z = (h_25.w - h_25.z);
  vec3 tmpvar_34;
  tmpvar_34 = normalize(tmpvar_33);
  vec3 normal_35;
  normal_35.xy = ((texture2D (_BumpMap, xlv_TEXCOORD0.zw).wy * 2.0) - 1.0);
  normal_35.z = sqrt((1.0 - clamp (
    dot (normal_35.xy, normal_35.xy)
  , 0.0, 1.0)));
  bump_13 = (normal_35 * mix (_BumpFace, _BumpOutline, clamp (
    (tmpvar_18 + (tmpvar_19 * 0.5))
  , 0.0, 1.0)));
  vec3 tmpvar_36;
  tmpvar_36 = mix (vec3(0.0, 0.0, 1.0), bump_13, faceColor_23.www);
  bump_13 = tmpvar_36;
  vec3 tmpvar_37;
  tmpvar_37 = normalize(((
    (tmpvar_32.yzx * tmpvar_34.zxy)
   - 
    (tmpvar_32.zxy * tmpvar_34.yzx)
  ) - tmpvar_36));
  mat3 tmpvar_38;
  tmpvar_38[0] = _Object2World[0].xyz;
  tmpvar_38[1] = _Object2World[1].xyz;
  tmpvar_38[2] = _Object2World[2].xyz;
  vec3 N_39;
  N_39 = (tmpvar_38 * tmpvar_37);
  vec3 tmpvar_40;
  tmpvar_40 = ((textureCube (_Cube, (xlv_TEXCOORD5 - 
    (2.0 * (dot (N_39, xlv_TEXCOORD5) * N_39))
  )).xyz * mix (_ReflectFaceColor.xyz, _ReflectOutlineColor.xyz, vec3(
    clamp ((tmpvar_18 + (tmpvar_19 * 0.5)), 0.0, 1.0)
  ))) * faceColor_23.w);
  tmpvar_9 = faceColor_15.xyz;
  tmpvar_10 = -(tmpvar_37);
  float tmpvar_41;
  tmpvar_41 = mix (_FaceShininess, _OutlineShininess, clamp ((tmpvar_18 + 
    (tmpvar_19 * 0.5)
  ), 0.0, 1.0));
  tmpvar_11 = 1.0;
  tmpvar_12 = faceColor_15.w;
  tmpvar_3 = tmpvar_9;
  tmpvar_5 = tmpvar_11;
  tmpvar_6 = tmpvar_12;
  c_2 = vec4(0.0, 0.0, 0.0, 0.0);
  worldN_1.x = dot (xlv_TEXCOORD1.xyz, tmpvar_10);
  worldN_1.y = dot (xlv_TEXCOORD2.xyz, tmpvar_10);
  worldN_1.z = dot (xlv_TEXCOORD3.xyz, tmpvar_10);
  tmpvar_4 = worldN_1;
  vec3 ambient_42;
  vec4 tmpvar_43;
  tmpvar_43.w = 1.0;
  tmpvar_43.xyz = worldN_1;
  vec3 x_44;
  x_44.x = dot (unity_SHAr, tmpvar_43);
  x_44.y = dot (unity_SHAg, tmpvar_43);
  x_44.z = dot (unity_SHAb, tmpvar_43);
  vec3 tmpvar_45;
  tmpvar_45 = max (vec3(0.0, 0.0, 0.0), (xlv_TEXCOORD6 + x_44));
  ambient_42 = tmpvar_45;
  if ((unity_ColorSpaceLuminance.w == 0.0)) {
    ambient_42 = max (((1.055 * 
      pow (max (tmpvar_45, vec3(0.0, 0.0, 0.0)), vec3(0.4166667, 0.4166667, 0.4166667))
    ) - 0.055), vec3(0.0, 0.0, 0.0));
  };
  vec4 c_46;
  vec4 c_47;
  c_47.xyz = (((faceColor_15.xyz * _LightColor0.xyz) * max (0.0, 
    dot (worldN_1, _WorldSpaceLightPos0.xyz)
  )) + ((_LightColor0.xyz * _SpecColor.xyz) * pow (
    max (0.0, dot (worldN_1, normalize((_WorldSpaceLightPos0.xyz + tmpvar_8))))
  , 
    (tmpvar_41 * 128.0)
  )));
  c_47.w = tmpvar_12;
  c_46.w = c_47.w;
  c_46.xyz = (c_47.xyz + (faceColor_15.xyz * ambient_42));
  c_2.w = c_46.w;
  c_2.xyz = (c_46.xyz + tmpvar_40);
  gl_FragData[0] = c_2;
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 135 math
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" "VERTEXLIGHT_ON" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
Matrix 14 [_EnvMatrix] 3
Matrix 8 [_Object2World] 3
Matrix 11 [_World2Object] 3
Matrix 4 [glstate_matrix_mvp]
Matrix 17 [glstate_matrix_projection] 2
Float 31 [_FaceDilate]
Vector 42 [_FaceTex_ST]
Float 37 [_GradientScale]
Vector 41 [_MainTex_ST]
Float 40 [_PerspectiveFilter]
Float 34 [_ScaleRatioA]
Float 38 [_ScaleX]
Float 39 [_ScaleY]
Vector 20 [_ScreenParams]
Float 35 [_VertexOffsetX]
Float 36 [_VertexOffsetY]
Float 33 [_WeightBold]
Float 32 [_WeightNormal]
Vector 19 [_WorldSpaceCameraPos]
Vector 24 [unity_4LightAtten0]
Vector 21 [unity_4LightPosX0]
Vector 22 [unity_4LightPosY0]
Vector 23 [unity_4LightPosZ0]
Vector 30 [unity_ColorSpaceLuminance]
Vector 0 [unity_LightColor0]
Vector 1 [unity_LightColor1]
Vector 2 [unity_LightColor2]
Vector 3 [unity_LightColor3]
Vector 27 [unity_SHBb]
Vector 26 [unity_SHBg]
Vector 25 [unity_SHBr]
Vector 28 [unity_SHC]
Vector 29 [unity_WorldTransformParams]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   row_major float4x4 _EnvMatrix;
//   float _FaceDilate;
//   float4 _FaceTex_ST;
//   float _GradientScale;
//   float4 _MainTex_ST;
//   row_major float4x4 _Object2World;
//   float _PerspectiveFilter;
//   float _ScaleRatioA;
//   float _ScaleX;
//   float _ScaleY;
//   float4 _ScreenParams;
//   float _VertexOffsetX;
//   float _VertexOffsetY;
//   float _WeightBold;
//   float _WeightNormal;
//   row_major float4x4 _World2Object;
//   float3 _WorldSpaceCameraPos;
//   row_major float4x4 glstate_matrix_mvp;
//   row_major float4x4 glstate_matrix_projection;
//   float4 unity_4LightAtten0;
//   float4 unity_4LightPosX0;
//   float4 unity_4LightPosY0;
//   float4 unity_4LightPosZ0;
//   float4 unity_ColorSpaceLuminance;
//   float4 unity_LightColor[8];
//   float4 unity_SHBb;
//   float4 unity_SHBg;
//   float4 unity_SHBr;
//   float4 unity_SHC;
//   float4 unity_WorldTransformParams;
//
//
// Registers:
//
//   Name                       Reg   Size
//   -------------------------- ----- ----
//   unity_LightColor           c0       4
//   glstate_matrix_mvp         c4       4
//   _Object2World              c8       3
//   _World2Object              c11      3
//   _EnvMatrix                 c14      3
//   glstate_matrix_projection  c17      2
//   _WorldSpaceCameraPos       c19      1
//   _ScreenParams              c20      1
//   unity_4LightPosX0          c21      1
//   unity_4LightPosY0          c22      1
//   unity_4LightPosZ0          c23      1
//   unity_4LightAtten0         c24      1
//   unity_SHBr                 c25      1
//   unity_SHBg                 c26      1
//   unity_SHBb                 c27      1
//   unity_SHC                  c28      1
//   unity_WorldTransformParams c29      1
//   unity_ColorSpaceLuminance  c30      1
//   _FaceDilate                c31      1
//   _WeightNormal              c32      1
//   _WeightBold                c33      1
//   _ScaleRatioA               c34      1
//   _VertexOffsetX             c35      1
//   _VertexOffsetY             c36      1
//   _GradientScale             c37      1
//   _ScaleX                    c38      1
//   _ScaleY                    c39      1
//   _PerspectiveFilter         c40      1
//   _MainTex_ST                c41      1
//   _FaceTex_ST                c42      1
//

    vs_3_0
    def c43, 0, 1, 1.5, 0.5
    def c44, 0.00122070313, 5, 0.305306017, 0.682171106
    def c45, 0.0125228781, 0, 0, 0
    dcl_position v0
    dcl_tangent v1
    dcl_normal v2
    dcl_texcoord v3
    dcl_texcoord1 v4
    dcl_color v5
    dcl_position o0
    dcl_texcoord o1
    dcl_texcoord1 o2
    dcl_texcoord2 o3
    dcl_texcoord3 o4
    dcl_color o5
    dcl_texcoord4 o6.xy
    dcl_texcoord5 o7.xyz
    dcl_texcoord6 o8.xyz
    mov r0.xy, c43
    add r0.z, r0.y, -c40.x
    mul r0.w, c37.x, v4_abs.y
    mov r1.xy, c20
    mul r1.zw, r1.xyxy, c17.xyxy
    add r1.z, r1.w, r1.z
    mul r1.z, r1.z, c38.x
    rcp r2.x, r1.z
    mul r1.xy, r1, c18
    add r1.x, r1.y, r1.x
    mul r1.x, r1.x, c39.x
    rcp r2.y, r1.x
    add r1.x, c35.x, v0.x
    add r1.y, c36.x, v0.y
    mov r1.zw, v0
    dp4 r2.z, c7, r1
    mul r2.xy, r2, r2.z
    mov o0.w, r2.z
    mul r2.xy, r2, r2
    add r2.x, r2.y, r2.x
    rsq r2.x, r2.x
    mul r0.w, r0.w, r2.x
    mul r2.x, r0.w, c43.z
    mul r0.z, r0.z, r2.x
    mad r0.w, r0.w, c43.z, -r0.z
    mad r2, c19.xyzx, r0.yyyx, r0.xxxy
    dp4 r3.x, c11, r2
    dp4 r3.y, c12, r2
    dp4 r3.z, c13, r2
    add r2.xyz, -r1, r3
    dp3 r0.x, v2, r2
    slt r2.x, -r0.x, r0.x
    slt r0.x, r0.x, -r0.x
    add r0.x, -r0.x, r2.x
    mul r2.xyz, r0.x, v2
    mul r3, r2.y, c12.xyzz
    mad r3, c11.xyzz, r2.x, r3
    mad r2, c13.xyzz, r2.z, r3
    dp3 r0.x, r2.xyww, r2.xyww
    rsq r0.x, r0.x
    mul r2, r0.x, r2
    dp4 r3.x, c8, r1
    dp4 r3.y, c9, r1
    dp4 r3.z, c10, r1
    add r4.xyz, -r3, c19
    nrm r5.xyz, r4
    dp3 r0.x, r2.xyww, r5
    mad o6.y, r0_abs.x, r0.w, r0.z
    sge r0.x, c43.x, v4.y
    mov r5.x, c32.x
    add r0.z, -r5.x, c33.x
    mad r0.x, r0.x, r0.z, c32.x
    mov r5.x, c31.x
    mul r0.z, r5.x, c34.x
    mul r0.z, r0.z, c43.w
    rcp r0.w, c37.x
    mad o6.x, r0.x, r0.w, r0.z
    dp3 o7.x, c14, r4
    dp3 o7.y, c15, r4
    dp3 o7.z, c16, r4
    dp4 o0.x, c4, r1
    dp4 o0.y, c5, r1
    dp4 o0.z, c6, r1
    mad o1.xy, v3, c41, c41.zwzw
    frc r0.x, v4.x
    add r0.z, -r0.x, v4.x
    mul r1.zw, r0.xyzx, c42.xyxy
    mov r1.xy, c44
    mad o1.zw, r1, r1.xyxy, c42
    add r1, -r3.z, c23
    mov o4.w, r3.z
    add r4, -r3.x, c21
    mov o2.w, r3.x
    add r5, -r3.y, c22
    mov o3.w, r3.y
    mul r3, r2.y, r5
    mul r5, r5, r5
    mad r5, r4, r4, r5
    mad r3, r4, r2.x, r3
    mad r3, r1, r2.wwzw, r3
    mad r1, r1, r1, r5
    rsq r4.x, r1.x
    rsq r4.y, r1.y
    rsq r4.z, r1.z
    rsq r4.w, r1.w
    mad r0, r1, c24, r0.y
    mul r1, r3, r4
    max r1, r1, c43.x
    rcp r3.x, r0.x
    rcp r3.y, r0.y
    rcp r3.z, r0.z
    rcp r3.w, r0.w
    mul r0, r1, r3
    mul r1.xyz, r0.y, c1
    mad r1.xyz, c0, r0.x, r1
    mad r0.xyz, c2, r0.z, r1
    mad r0.xyz, c3, r0.w, r0
    mad r1.xyz, r0, c44.z, c44.w
    mad r1.xyz, r0, r1, c45.x
    mad r1.xyz, r0, r1, -r0
    abs r0.w, c30.w
    sge r0.w, -r0.w, r0.w
    mad r0.xyz, r0.w, r1, r0
    mul r0.w, r2.y, r2.y
    mad r0.w, r2.x, r2.x, -r0.w
    mul r1, r2.ywzx, r2
    dp4 r3.x, c25, r1
    dp4 r3.y, c26, r1
    dp4 r3.z, c27, r1
    mad r1.xyz, c28, r0.w, r3
    add o8.xyz, r0, r1
    dp3 r0.z, c8, v1
    dp3 r0.x, c9, v1
    dp3 r0.y, c10, v1
    dp3 r0.w, r0, r0
    rsq r0.w, r0.w
    mul r0.xyz, r0.w, r0
    mov o2.x, r0.z
    mul r1.xyz, r0, r2.wxyw
    mad r1.xyz, r2.ywxw, r0.yzxw, -r1
    mul r0.z, c29.w, v1.w
    mul r1.xyz, r0.z, r1
    mov o2.y, r1.x
    mov o2.z, r2.x
    mov o3.x, r0.x
    mov o4.x, r0.y
    mov o3.y, r1.y
    mov o4.y, r1.z
    mov o3.z, r2.y
    mov o4.z, r2.w
    mov o5, v5

// approximately 133 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 104 math
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" "VERTEXLIGHT_ON" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
ConstBuffer "$Globals" 592
Matrix 272 [_EnvMatrix]
Vector 48 [unity_ColorSpaceLuminance]
Float 160 [_FaceDilate]
Float 452 [_WeightNormal]
Float 456 [_WeightBold]
Float 460 [_ScaleRatioA]
Float 472 [_VertexOffsetX]
Float 476 [_VertexOffsetY]
Float 528 [_GradientScale]
Float 532 [_ScaleX]
Float 536 [_ScaleY]
Float 540 [_PerspectiveFilter]
Vector 560 [_MainTex_ST]
Vector 576 [_FaceTex_ST]
ConstBuffer "UnityPerCamera" 144
Vector 64 [_WorldSpaceCameraPos] 3
Vector 96 [_ScreenParams]
ConstBuffer "UnityLighting" 720
Vector 32 [unity_4LightPosX0]
Vector 48 [unity_4LightPosY0]
Vector 64 [unity_4LightPosZ0]
Vector 80 [unity_4LightAtten0]
Vector 96 [unity_LightColor0]
Vector 112 [unity_LightColor1]
Vector 128 [unity_LightColor2]
Vector 144 [unity_LightColor3]
Vector 160 [unity_LightColor4]
Vector 176 [unity_LightColor5]
Vector 192 [unity_LightColor6]
Vector 208 [unity_LightColor7]
Vector 656 [unity_SHBr]
Vector 672 [unity_SHBg]
Vector 688 [unity_SHBb]
Vector 704 [unity_SHC]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
Matrix 256 [_World2Object]
Vector 336 [unity_WorldTransformParams]
ConstBuffer "UnityPerFrame" 256
Matrix 0 [glstate_matrix_projection]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityLighting" 2
BindCB  "UnityPerDraw" 3
BindCB  "UnityPerFrame" 4
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// TANGENT                  0   xyzw        1     NONE   float   xyzw
// NORMAL                   0   xyz         2     NONE   float   xyz 
// TEXCOORD                 0   xyzw        3     NONE   float   xy  
// TEXCOORD                 1   xyzw        4     NONE   float   xy  
// TEXCOORD                 2   xyzw        5     NONE   float       
// TEXCOORD                 3   xyzw        6     NONE   float       
// COLOR                    0   xyzw        7     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyzw        2     NONE   float   xyzw
// TEXCOORD                 2   xyzw        3     NONE   float   xyzw
// TEXCOORD                 3   xyzw        4     NONE   float   xyzw
// COLOR                    0   xyzw        5     NONE   float   xyzw
// TEXCOORD                 4   xy          6     NONE   float   xy  
// TEXCOORD                 5   xyz         7     NONE   float   xyz 
// TEXCOORD                 6   xyz         8     NONE   float   xyz 
//
      vs_4_0
      dcl_constantbuffer cb0[37], immediateIndexed
      dcl_constantbuffer cb1[7], immediateIndexed
      dcl_constantbuffer cb2[45], immediateIndexed
      dcl_constantbuffer cb3[22], immediateIndexed
      dcl_constantbuffer cb4[2], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v1.xyzw
      dcl_input v2.xyz
      dcl_input v3.xy
      dcl_input v4.xy
      dcl_input v7.xyzw
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xyzw
      dcl_output o2.xyzw
      dcl_output o3.xyzw
      dcl_output o4.xyzw
      dcl_output o5.xyzw
      dcl_output o6.xy
      dcl_output o7.xyz
      dcl_output o8.xyz
      dcl_temps 5
   0: add r0.xy, v0.xyxx, cb0[29].zwzz
   1: mul r1.xyzw, r0.yyyy, cb3[1].xyzw
   2: mad r1.xyzw, cb3[0].xyzw, r0.xxxx, r1.xyzw
   3: mad r1.xyzw, cb3[2].xyzw, v0.zzzz, r1.xyzw
   4: mad o0.xyzw, cb3[3].xyzw, v0.wwww, r1.xyzw
   5: round_ni r0.w, v4.x
   6: mul r1.z, r0.w, cb0[36].x
   7: frc r0.w, v4.x
   8: mul r1.w, r0.w, cb0[36].y
   9: mad o1.zw, r1.zzzw, l(0.000000, 0.000000, 0.001221, 5.000000), cb0[36].zzzw
  10: mad o1.xy, v3.xyxx, cb0[35].xyxx, cb0[35].zwzz
  11: mul r1.xyz, cb1[4].yyyy, cb3[17].xyzx
  12: mad r1.xyz, cb3[16].xyzx, cb1[4].xxxx, r1.xyzx
  13: mad r1.xyz, cb3[18].xyzx, cb1[4].zzzz, r1.xyzx
  14: add r1.xyz, r1.xyzx, cb3[19].xyzx
  15: mov r0.z, v0.z
  16: add r1.xyz, -r0.xyzx, r1.xyzx
  17: dp3 r0.z, v2.xyzx, r1.xyzx
  18: lt r0.w, l(0.000000), r0.z
  19: lt r0.z, r0.z, l(0.000000)
  20: iadd r0.z, -r0.w, r0.z
  21: itof r0.z, r0.z
  22: mul r1.xyz, r0.zzzz, v2.xyzx
  23: mov r2.x, cb3[16].y
  24: mov r2.y, cb3[17].y
  25: mov r2.zw, cb3[18].yyyy
  26: mul r2.xyzw, r1.yyyy, r2.xyzw
  27: mov r3.x, cb3[16].x
  28: mov r3.y, cb3[17].x
  29: mov r3.zw, cb3[18].xxxx
  30: mad r2.xyzw, r3.xyzw, r1.xxxx, r2.xyzw
  31: mov r3.x, cb3[16].z
  32: mov r3.y, cb3[17].z
  33: mov r3.zw, cb3[18].zzzz
  34: mad r1.xyzw, r3.xyzw, r1.zzzz, r2.xyzw
  35: dp3 r0.z, r1.xywx, r1.xywx
  36: rsq r0.z, r0.z
  37: mul r1.xyzw, r0.zzzz, r1.xyzw
  38: mul r2.xyz, v1.yyyy, cb3[13].yzxy
  39: mad r2.xyz, cb3[12].yzxy, v1.xxxx, r2.xyzx
  40: mad r2.xyz, cb3[14].yzxy, v1.zzzz, r2.xyzx
  41: dp3 r0.z, r2.xyzx, r2.xyzx
  42: rsq r0.z, r0.z
  43: mul r2.xyz, r0.zzzz, r2.xyzx
  44: mul r3.xyz, r1.wxyw, r2.xyzx
  45: mad r3.xyz, r1.ywxy, r2.yzxy, -r3.xyzx
  46: mul r0.z, v1.w, cb3[21].w
  47: mul r3.xyz, r0.zzzz, r3.xyzx
  48: mov o2.y, r3.x
  49: mov o2.z, r1.x
  50: mov o2.x, r2.z
  51: mul r4.xyz, r0.yyyy, cb3[13].xyzx
  52: mad r4.xyz, cb3[12].xyzx, r0.xxxx, r4.xyzx
  53: mad r4.xyz, cb3[14].xyzx, v0.zzzz, r4.xyzx
  54: mad r4.xyz, cb3[15].xyzx, v0.wwww, r4.xyzx
  55: mov o2.w, r4.x
  56: mov o3.x, r2.x
  57: mov o4.x, r2.y
  58: mov o3.z, r1.y
  59: mov o3.y, r3.y
  60: mov o4.y, r3.z
  61: mov o3.w, r4.y
  62: mov o4.z, r1.w
  63: mov o4.w, r4.z
  64: mov o5.xyzw, v7.xyzw
  65: ge r0.z, l(0.000000), v4.y
  66: and r0.z, r0.z, l(0x3f800000)
  67: add r0.w, -cb0[28].y, cb0[28].z
  68: mad r0.z, r0.z, r0.w, cb0[28].y
  69: div r0.z, r0.z, cb0[33].x
  70: mul r0.w, cb0[10].x, cb0[28].w
  71: mad o6.x, r0.w, l(0.500000), r0.z
  72: mul r0.y, r0.y, cb3[1].w
  73: mad r0.x, cb3[0].w, r0.x, r0.y
  74: mad r0.x, cb3[2].w, v0.z, r0.x
  75: mad r0.x, cb3[3].w, v0.w, r0.x
  76: mul r0.yz, cb1[6].yyyy, cb4[1].xxyx
  77: mad r0.yz, cb4[0].xxyx, cb1[6].xxxx, r0.yyzy
  78: mul r0.yz, r0.yyzy, cb0[33].yyzy
  79: div r0.xy, r0.xxxx, r0.yzyy
  80: dp2 r0.x, r0.xyxx, r0.xyxx
  81: rsq r0.x, r0.x
  82: mul r0.y, |v4.y|, cb0[33].x
  83: mul r0.x, r0.x, r0.y
  84: mul r0.y, r0.x, l(1.500000)
  85: add r0.z, -cb0[33].w, l(1.000000)
  86: mul r0.y, r0.z, r0.y
  87: mad r0.x, r0.x, l(1.500000), -r0.y
  88: add r2.xyz, -r4.xyzx, cb1[4].xyzx
  89: dp3 r0.z, r2.xyzx, r2.xyzx
  90: rsq r0.z, r0.z
  91: mul r3.xyz, r0.zzzz, r2.xyzx
  92: dp3 r0.z, r1.xywx, r3.xyzx
  93: mad o6.y, |r0.z|, r0.x, r0.y
  94: mul r0.xyz, r2.yyyy, cb0[18].xyzx
  95: mad r0.xyz, cb0[17].xyzx, r2.xxxx, r0.xyzx
  96: mad o7.xyz, cb0[19].xyzx, r2.zzzz, r0.xyzx
  97: add r0.xyzw, -r4.yyyy, cb2[3].xyzw
  98: mul r2.xyzw, r1.yyyy, r0.xyzw
  99: mul r0.xyzw, r0.xyzw, r0.xyzw
 100: add r3.xyzw, -r4.xxxx, cb2[2].xyzw
 101: add r4.xyzw, -r4.zzzz, cb2[4].xyzw
 102: mad r2.xyzw, r3.xyzw, r1.xxxx, r2.xyzw
 103: mad r0.xyzw, r3.xyzw, r3.xyzw, r0.xyzw
 104: mad r0.xyzw, r4.xyzw, r4.xyzw, r0.xyzw
 105: mad r2.xyzw, r4.xyzw, r1.wwzw, r2.xyzw
 106: rsq r3.xyzw, r0.xyzw
 107: mad r0.xyzw, r0.xyzw, cb2[5].xyzw, l(1.000000, 1.000000, 1.000000, 1.000000)
 108: div r0.xyzw, l(1.000000, 1.000000, 1.000000, 1.000000), r0.xyzw
 109: mul r2.xyzw, r2.xyzw, r3.xyzw
 110: max r2.xyzw, r2.xyzw, l(0.000000, 0.000000, 0.000000, 0.000000)
 111: mul r0.xyzw, r0.xyzw, r2.xyzw
 112: mul r2.xyz, r0.yyyy, cb2[7].xyzx
 113: mad r2.xyz, cb2[6].xyzx, r0.xxxx, r2.xyzx
 114: mad r0.xyz, cb2[8].xyzx, r0.zzzz, r2.xyzx
 115: mad r0.xyz, cb2[9].xyzx, r0.wwww, r0.xyzx
 116: mad r2.xyz, r0.xyzx, l(0.305306, 0.305306, 0.305306, 0.000000), l(0.682171, 0.682171, 0.682171, 0.000000)
 117: mad r2.xyz, r0.xyzx, r2.xyzx, l(0.012523, 0.012523, 0.012523, 0.000000)
 118: mul r2.xyz, r0.xyzx, r2.xyzx
 119: eq r0.w, cb0[3].w, l(0.000000)
 120: movc r0.xyz, r0.wwww, r2.xyzx, r0.xyzx
 121: mul r0.w, r1.y, r1.y
 122: mad r0.w, r1.x, r1.x, -r0.w
 123: mul r1.xyzw, r1.ywzx, r1.xyzw
 124: dp4 r2.x, cb2[41].xyzw, r1.xyzw
 125: dp4 r2.y, cb2[42].xyzw, r1.xyzw
 126: dp4 r2.z, cb2[43].xyzw, r1.xyzw
 127: mad r1.xyz, cb2[44].xyzx, r0.wwww, r2.xyzx
 128: add o8.xyz, r0.xyzx, r1.xyzx
 129: ret 
// Approximately 0 instruction slots used
"
}
}
Program "fp" {
SubProgram "opengl " {
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" }
"// shader disassembly not supported on opengl"
}
SubProgram "d3d9 " {
// Stats: 170 math, 9 textures
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" }
Matrix 0 [_Object2World] 3
Float 20 [_Bevel]
Float 23 [_BevelClamp]
Float 21 [_BevelOffset]
Float 24 [_BevelRoundness]
Float 22 [_BevelWidth]
Float 26 [_BumpFace]
Float 25 [_BumpOutline]
Vector 14 [_FaceColor]
Float 34 [_FaceShininess]
Float 12 [_FaceUVSpeedX]
Float 13 [_FaceUVSpeedY]
Float 33 [_GradientScale]
Vector 10 [_LightColor0]
Vector 18 [_OutlineColor]
Float 35 [_OutlineShininess]
Float 15 [_OutlineSoftness]
Float 16 [_OutlineUVSpeedX]
Float 17 [_OutlineUVSpeedY]
Float 19 [_OutlineWidth]
Vector 27 [_ReflectFaceColor]
Vector 28 [_ReflectOutlineColor]
Float 30 [_ScaleRatioA]
Float 29 [_ShaderFlags]
Vector 11 [_SpecColor]
Float 32 [_TextureHeight]
Float 31 [_TextureWidth]
Vector 3 [_Time]
Vector 4 [_WorldSpaceCameraPos]
Vector 5 [_WorldSpaceLightPos0]
Vector 9 [unity_ColorSpaceLuminance]
Vector 8 [unity_SHAb]
Vector 7 [unity_SHAg]
Vector 6 [unity_SHAr]
SetTexture 0 [_FaceTex] 2D 0
SetTexture 1 [_OutlineTex] 2D 1
SetTexture 2 [_BumpMap] 2D 2
SetTexture 3 [_Cube] CUBE 3
SetTexture 4 [_MainTex] 2D 4
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float _Bevel;
//   float _BevelClamp;
//   float _BevelOffset;
//   float _BevelRoundness;
//   float _BevelWidth;
//   float _BumpFace;
//   sampler2D _BumpMap;
//   float _BumpOutline;
//   samplerCUBE _Cube;
//   float4 _FaceColor;
//   float _FaceShininess;
//   sampler2D _FaceTex;
//   float _FaceUVSpeedX;
//   float _FaceUVSpeedY;
//   float _GradientScale;
//   float4 _LightColor0;
//   sampler2D _MainTex;
//   row_major float4x4 _Object2World;
//   float4 _OutlineColor;
//   float _OutlineShininess;
//   float _OutlineSoftness;
//   sampler2D _OutlineTex;
//   float _OutlineUVSpeedX;
//   float _OutlineUVSpeedY;
//   float _OutlineWidth;
//   float4 _ReflectFaceColor;
//   float4 _ReflectOutlineColor;
//   float _ScaleRatioA;
//   float _ShaderFlags;
//   float4 _SpecColor;
//   float _TextureHeight;
//   float _TextureWidth;
//   float4 _Time;
//   float3 _WorldSpaceCameraPos;
//   float4 _WorldSpaceLightPos0;
//   float4 unity_ColorSpaceLuminance;
//   float4 unity_SHAb;
//   float4 unity_SHAg;
//   float4 unity_SHAr;
//
//
// Registers:
//
//   Name                      Reg   Size
//   ------------------------- ----- ----
//   _Object2World             c0       3
//   _Time                     c3       1
//   _WorldSpaceCameraPos      c4       1
//   _WorldSpaceLightPos0      c5       1
//   unity_SHAr                c6       1
//   unity_SHAg                c7       1
//   unity_SHAb                c8       1
//   unity_ColorSpaceLuminance c9       1
//   _LightColor0              c10      1
//   _SpecColor                c11      1
//   _FaceUVSpeedX             c12      1
//   _FaceUVSpeedY             c13      1
//   _FaceColor                c14      1
//   _OutlineSoftness          c15      1
//   _OutlineUVSpeedX          c16      1
//   _OutlineUVSpeedY          c17      1
//   _OutlineColor             c18      1
//   _OutlineWidth             c19      1
//   _Bevel                    c20      1
//   _BevelOffset              c21      1
//   _BevelWidth               c22      1
//   _BevelClamp               c23      1
//   _BevelRoundness           c24      1
//   _BumpOutline              c25      1
//   _BumpFace                 c26      1
//   _ReflectFaceColor         c27      1
//   _ReflectOutlineColor      c28      1
//   _ShaderFlags              c29      1
//   _ScaleRatioA              c30      1
//   _TextureWidth             c31      1
//   _TextureHeight            c32      1
//   _GradientScale            c33      1
//   _FaceShininess            c34      1
//   _OutlineShininess         c35      1
//   _FaceTex                  s0       1
//   _OutlineTex               s1       1
//   _BumpMap                  s2       1
//   _Cube                     s3       1
//   _MainTex                  s4       1
//

    ps_3_0
    def c36, 10000, 0.00999999978, 2, -1
    def c37, 0.249999955, 0.25, 6.28318548, -3.14159274
    def c38, -2.52398507e-007, 2.47609005e-005, -0.00138883968, 0.0416666418
    def c39, 0.416666657, 1.05499995, -0.0549999997, 128
    def c40, 0, 0.5, 1, -9.99999975e-005
    dcl_texcoord v0
    dcl_texcoord1 v1
    dcl_texcoord2 v2
    dcl_texcoord3 v3
    dcl_color_pp v4
    dcl_texcoord4 v5.xy
    dcl_texcoord5 v6.xyz
    dcl_texcoord6_pp v7.xyz
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    dcl_cube s3
    dcl_2d s4
    mov r0.x, v1.w
    mov r0.y, v2.w
    mov r0.z, v3.w
    add r0.xyz, -r0, c4
    dp3 r0.w, r0, r0
    rsq r0.w, r0.w
    mad_pp r0.xyz, r0, r0.w, c5
    nrm_pp r1.xyz, r0
    add r0.x, c21.x, v5.x
    rcp r2.x, c31.x
    rcp r2.w, c32.x
    mov r2.yz, c40.x
    add r3, -r2, v0.xyxy
    add r2, r2, v0.xyxy
    texld r4, r3, s4
    texld r3, r3.zwzw, s4
    mov r3.z, r3.w
    mov r3.x, r4.w
    texld r4, r2, s4
    texld r2, r2.zwzw, s4
    mov r3.w, r2.w
    mov r3.y, r4.w
    add r0, r0.x, r3
    mov r2.x, c19.x
    add r1.w, r2.x, c22.x
    max r2.y, c36.y, r1.w
    rcp r1.w, r2.y
    mul r2.y, r2.y, c20.x
    mul r2.y, r2.y, c33.x
    mul r2.y, r2.y, -c36.z
    lrp_sat r3, r1.w, r0, c40.y
    mad r0, r3, c36.z, c36.w
    add r0, -r0_abs, c40.z
    mov r4.yz, c40
    mul r1.w, r4.y, c29.x
    frc r1.w, r1_abs.w
    cmp r1.w, c29.x, r1.w, -r1.w
    add r1.w, r1.w, -c40.y
    cmp r0, r1.w, r0, r3
    mad r3, r0, c37.x, c37.y
    frc r3, r3
    mad r3, r3, c37.z, c37.w
    mul r3, r3, r3
    mad r5, r3, c38.x, c38.y
    mad r5, r3, r5, c38.z
    mad r5, r3, r5, c38.w
    mad r5, r3, r5, -c40.y
    mad r3, r3, r5, c40.z
    lrp r5, c24.x, r3, r0
    add r0.x, r4.z, -c23.x
    min r3, r0.x, r5
    mul r0.xy, r2.y, r3.xzzw
    mad r0.xy, r3.ywzw, r2.y, -r0
    mov r0.w, -c40.z
    dp2add r1.w, r0.wyzw, r0.wyzw, c40.x
    mul r2.yzw, r0.xwyw, c40.xzzx
    rsq r0.y, r1.w
    mul r2.yzw, r0.y, r2
    mov r0.z, c40.z
    dp2add r0.y, r0.zxzw, r0.zxzw, c40.x
    rsq r0.y, r0.y
    mul r3.x, r0.y, r0.x
    mul r3.yz, r0.y, c40.xzxw
    mul r0.xyz, r2.yzww, r3
    mad r0.xyz, r3.zxyw, r2.zwyw, -r0
    mov r2.y, c3.y
    mad r3.x, c16.x, r2.y, v0.z
    mad r3.y, c17.x, r2.y, v0.w
    texld r3, r3, s1
    mul_pp r3.xyz, r3, c18
    mul r0.w, c18.w, v4.w
    mul_pp r4.w, r3.w, r0.w
    mul_pp r4.xyz, r3, r4.w
    mad r3.x, c12.x, r2.y, v0.z
    mad r3.y, c13.x, r2.y, v0.w
    texld r3, r3, s0
    mul r5, c14, v4
    mul_pp r3, r3, r5
    mul_pp r3.xyz, r3.w, r3
    mul r0.w, r2.x, c30.x
    mad r1.w, r0.w, -v5.y, c40.z
    mul_pp r0.w, r0.w, v5.y
    rsq r2.x, r0.w
    rcp_pp r2.x, r2.x
    cmp_pp r1.w, r1.w, r2.x, c40.z
    texld r2, v0, s4
    add r2.x, -r2.w, c40.y
    add r2.x, r2.x, -v5.x
    mad_pp r2.x, r2.x, v5.y, c40.y
    mad_sat_pp r2.y, r0.w, c40.y, r2.x
    mad_pp r0.w, r0.w, -c40.y, r2.x
    mul_pp r1.w, r1.w, r2.y
    lrp_pp r5, r1.w, r4, r3
    mov r2.x, c30.x
    mul r1.w, r2.x, c15.x
    mul_pp r2.x, r1.w, v5.y
    mad_pp r1.w, r1.w, v5.y, c40.z
    rcp r1.w, r1.w
    mad_pp r0.w, r2.x, c40.y, r0.w
    mul_sat_pp r0.w, r1.w, r0.w
    add_pp r0.w, -r0.w, c40.z
    mul_pp r3, r0.w, r5
    mad r0.w, r5.w, r0.w, c40.w
    mov r2.x, c26.x
    add r1.w, -r2.x, c25.x
    mad r1.w, r2.y, r1.w, c26.x
    texld_pp r4, v0.zwzw, s2
    mad_pp r4.xy, r4.wyzw, c36.z, c36.w
    dp2add_sat_pp r2.x, r4, r4, c40.x
    add_pp r2.x, -r2.x, c40.z
    rsq_pp r2.x, r2.x
    rcp_pp r4.z, r2.x
    mad r2.xzw, r4.xyyz, r1.w, -c40.xyxz
    mad r2.xzw, r3.w, r2, c40.xyxz
    add r0.xyz, r0, -r2.xzww
    nrm r4.xyz, r0
    dp3_pp r5.x, v1, -r4
    dp3_pp r5.y, v2, -r4
    dp3_pp r5.z, v3, -r4
    dp3_pp r0.x, r5, r1
    max r1.x, r0.x, c40.x
    mov r0.x, c34.x
    add r0.x, -r0.x, c35.x
    mad_pp r0.x, r2.y, r0.x, c34.x
    mul r0.x, r0.x, c39.w
    pow r2.x, r1.x, r0.x
    mov r0.xyz, c10
    mul r0.xyz, r0, c11
    mul r0.xyz, r2.x, r0
    rcp r1.x, r3.w
    cmp r0.w, r0.w, r1.x, c36.x
    mul_pp r1.xyz, r0.w, r3
    mul_pp r2.xzw, r1.xyyz, c10.xyyz
    dp3_pp r0.w, r5, c5
    max_pp r1.w, r0.w, c40.x
    mad_pp r0.xyz, r2.xzww, r1.w, r0
    mov r5.w, c40.z
    dp4_pp r3.x, c6, r5
    dp4_pp r3.y, c7, r5
    dp4_pp r3.z, c8, r5
    add_pp r2.xzw, r3.xyyz, v7.xyyz
    max_pp r3.xyz, r2.xzww, c40.x
    log_pp r5.x, r3.x
    log_pp r5.y, r3.y
    log_pp r5.z, r3.z
    mul_pp r2.xzw, r5.xyyz, c39.x
    exp_pp r5.x, r2.x
    exp_pp r5.y, r2.z
    exp_pp r5.z, r2.w
    mad_pp r2.xzw, r5.xyyz, c39.y, c39.z
    max_pp r5.xyz, r2.xzww, c40.x
    abs r0.w, c9.w
    cmp_pp r2.xzw, -r0.w, r5.xyyz, r3.xyyz
    mad_pp r0.xyz, r1, r2.xzww, r0
    mov r1.xyz, c27
    add r1.xyz, -r1, c28
    mad r1.xyz, r2.y, r1, c27
    dp3 r2.x, c0, r4
    dp3 r2.y, c1, r4
    dp3 r2.z, c2, r4
    dp3 r0.w, v6, r2
    add r0.w, r0.w, r0.w
    mad r2.xyz, r2, -r0.w, v6
    texld_pp r2, r2, s3
    mul r1.xyz, r1, r2
    mad_pp oC0.xyz, r1, r3.w, r0
    mov_pp oC0.w, r3.w

// approximately 176 instruction slots used (9 texture, 167 arithmetic)
"
}
SubProgram "d3d11 " {
// Stats: 125 math, 9 textures
Keywords { "DIRECTIONAL" "LIGHTMAP_OFF" "DIRLIGHTMAP_OFF" "DYNAMICLIGHTMAP_OFF" }
SetTexture 0 [_MainTex] 2D 4
SetTexture 1 [_FaceTex] 2D 0
SetTexture 2 [_OutlineTex] 2D 1
SetTexture 3 [_BumpMap] 2D 2
SetTexture 4 [_Cube] CUBE 3
ConstBuffer "$Globals" 592
Vector 48 [unity_ColorSpaceLuminance]
Vector 96 [_LightColor0]
Vector 112 [_SpecColor]
Float 128 [_FaceUVSpeedX]
Float 132 [_FaceUVSpeedY]
Vector 144 [_FaceColor]
Float 164 [_OutlineSoftness]
Float 168 [_OutlineUVSpeedX]
Float 172 [_OutlineUVSpeedY]
Vector 176 [_OutlineColor]
Float 192 [_OutlineWidth]
Float 196 [_Bevel]
Float 200 [_BevelOffset]
Float 204 [_BevelWidth]
Float 208 [_BevelClamp]
Float 212 [_BevelRoundness]
Float 216 [_BumpOutline]
Float 220 [_BumpFace]
Vector 224 [_ReflectFaceColor]
Vector 240 [_ReflectOutlineColor]
Float 448 [_ShaderFlags]
Float 460 [_ScaleRatioA]
Float 520 [_TextureWidth]
Float 524 [_TextureHeight]
Float 528 [_GradientScale]
Float 544 [_FaceShininess]
Float 548 [_OutlineShininess]
ConstBuffer "UnityPerCamera" 144
Vector 0 [_Time]
Vector 64 [_WorldSpaceCameraPos] 3
ConstBuffer "UnityLighting" 720
Vector 0 [_WorldSpaceLightPos0]
Vector 608 [unity_SHAr]
Vector 624 [unity_SHAg]
Vector 640 [unity_SHAb]
ConstBuffer "UnityPerDraw" 352
Matrix 192 [_Object2World]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityLighting" 2
BindCB  "UnityPerDraw" 3
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyzw        2     NONE   float   xyzw
// TEXCOORD                 2   xyzw        3     NONE   float   xyzw
// TEXCOORD                 3   xyzw        4     NONE   float   xyzw
// COLOR                    0   xyzw        5     NONE   float   xyzw
// TEXCOORD                 4   xy          6     NONE   float   xy  
// TEXCOORD                 5   xyz         7     NONE   float   xyz 
// TEXCOORD                 6   xyz         8     NONE   float   xyz 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
      ps_4_0
      dcl_constantbuffer cb0[35], immediateIndexed
      dcl_constantbuffer cb1[5], immediateIndexed
      dcl_constantbuffer cb2[41], immediateIndexed
      dcl_constantbuffer cb3[15], immediateIndexed
      dcl_sampler s0, mode_default
      dcl_sampler s1, mode_default
      dcl_sampler s2, mode_default
      dcl_sampler s3, mode_default
      dcl_sampler s4, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_resource_texture2d (float,float,float,float) t1
      dcl_resource_texture2d (float,float,float,float) t2
      dcl_resource_texture2d (float,float,float,float) t3
      dcl_resource_texturecube (float,float,float,float) t4
      dcl_input_ps linear v1.xyzw
      dcl_input_ps linear v2.xyzw
      dcl_input_ps linear v3.xyzw
      dcl_input_ps linear v4.xyzw
      dcl_input_ps linear v5.xyzw
      dcl_input_ps linear v6.xy
      dcl_input_ps linear v7.xyz
      dcl_input_ps linear v8.xyz
      dcl_output o0.xyzw
      dcl_temps 6
   0: mov r0.x, v2.w
   1: mov r0.y, v3.w
   2: mov r0.z, v4.w
   3: add r0.xyz, -r0.xyzx, cb1[4].xyzx
   4: dp3 r0.w, r0.xyzx, r0.xyzx
   5: rsq r0.w, r0.w
   6: mad r0.xyz, r0.xyzx, r0.wwww, cb2[0].xyzx
   7: dp3 r0.w, r0.xyzx, r0.xyzx
   8: rsq r0.w, r0.w
   9: mul r0.xyz, r0.wwww, r0.xyzx
  10: add r0.w, v6.x, cb0[12].z
  11: div r1.xy, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[32].zwzz
  12: mov r1.z, l(0)
  13: add r2.xyzw, -r1.xzzy, v1.xyxy
  14: add r1.xyzw, r1.xzzy, v1.xyxy
  15: sample r3.xyzw, r2.xyxx, t0.wxyz, s4
  16: sample r2.xyzw, r2.zwzz, t0.xyzw, s4
  17: mov r3.z, r2.w
  18: sample r2.xyzw, r1.xyxx, t0.xyzw, s4
  19: sample r1.xyzw, r1.zwzz, t0.xyzw, s4
  20: mov r3.w, r1.w
  21: mov r3.y, r2.w
  22: add r1.xyzw, r0.wwww, r3.xyzw
  23: add r1.xyzw, r1.xyzw, l(-0.500000, -0.500000, -0.500000, -0.500000)
  24: add r0.w, cb0[12].w, cb0[12].x
  25: max r0.w, r0.w, l(0.010000)
  26: div r1.xyzw, r1.xyzw, r0.wwww
  27: mul r0.w, r0.w, cb0[12].y
  28: mul r0.w, r0.w, cb0[33].x
  29: mul r0.w, r0.w, l(-2.000000)
  30: add_sat r1.xyzw, r1.xyzw, l(0.500000, 0.500000, 0.500000, 0.500000)
  31: mad r2.xyzw, r1.xyzw, l(2.000000, 2.000000, 2.000000, 2.000000), l(-1.000000, -1.000000, -1.000000, -1.000000)
  32: add r2.xyzw, -|r2.xyzw|, l(1.000000, 1.000000, 1.000000, 1.000000)
  33: mul r3.x, cb0[28].x, l(0.500000)
  34: ge r3.y, r3.x, -r3.x
  35: frc r3.x, |r3.x|
  36: movc r3.x, r3.y, r3.x, -r3.x
  37: ge r3.x, r3.x, l(0.500000)
  38: movc r1.xyzw, r3.xxxx, r2.xyzw, r1.xyzw
  39: mul r2.xyzw, r1.xyzw, l(1.570796, 1.570796, 1.570796, 1.570796)
  40: sincos r2.xyzw, null, r2.xyzw
  41: add r2.xyzw, -r1.xyzw, r2.xyzw
  42: mad r1.xyzw, cb0[13].yyyy, r2.xyzw, r1.xyzw
  43: add r2.x, -cb0[13].x, l(1.000000)
  44: min r1.xyzw, r1.xyzw, r2.xxxx
  45: mul r1.xz, r0.wwww, r1.xxzx
  46: mad r1.yz, r1.wwyw, r0.wwww, -r1.zzxz
  47: mov r1.xw, l(-1.000000,0,0,1.000000)
  48: dp2 r0.w, r1.xyxx, r1.xyxx
  49: rsq r0.w, r0.w
  50: dp2 r1.w, r1.zwzz, r1.zwzz
  51: rsq r1.w, r1.w
  52: mul r2.x, r1.w, r1.z
  53: mul r2.yz, r1.wwww, l(0.000000, 1.000000, 0.000000, 0.000000)
  54: mov r1.z, l(0)
  55: mul r1.xyz, r0.wwww, r1.xyzx
  56: mul r3.xyz, r1.xyzx, r2.xyzx
  57: mad r1.xyz, r2.zxyz, r1.yzxy, -r3.xyzx
  58: mad r2.xy, cb0[10].zwzz, cb1[0].yyyy, v1.zwzz
  59: sample r2.xyzw, r2.xyxx, t2.xyzw, s1
  60: mul r2.xyz, r2.xyzx, cb0[11].xyzx
  61: mul r0.w, v5.w, cb0[11].w
  62: mul r3.w, r2.w, r0.w
  63: mul r3.xyz, r2.xyzx, r3.wwww
  64: mad r2.xy, cb0[8].xyxx, cb1[0].yyyy, v1.zwzz
  65: sample r2.xyzw, r2.xyxx, t1.xyzw, s0
  66: mul r4.xyzw, v5.xyzw, cb0[9].xyzw
  67: mul r2.xyzw, r2.xyzw, r4.xyzw
  68: mul r2.xyz, r2.wwww, r2.xyzx
  69: add r3.xyzw, -r2.xyzw, r3.xyzw
  70: mul r0.w, cb0[12].x, cb0[28].w
  71: mul r0.w, r0.w, v6.y
  72: min r1.w, r0.w, l(1.000000)
  73: sqrt r1.w, r1.w
  74: sample r4.xyzw, v1.xyxx, t0.xyzw, s4
  75: add r4.x, -r4.w, l(0.500000)
  76: add r4.x, r4.x, -v6.x
  77: mad r4.x, r4.x, v6.y, l(0.500000)
  78: mad_sat r4.y, r0.w, l(0.500000), r4.x
  79: mad r0.w, -r0.w, l(0.500000), r4.x
  80: mul r1.w, r1.w, r4.y
  81: mad r2.xyzw, r1.wwww, r3.xyzw, r2.xyzw
  82: mul r1.w, cb0[10].y, cb0[28].w
  83: mul r3.x, r1.w, v6.y
  84: mad r1.w, r1.w, v6.y, l(1.000000)
  85: mad r0.w, r3.x, l(0.500000), r0.w
  86: div_sat r0.w, r0.w, r1.w
  87: add r0.w, -r0.w, l(1.000000)
  88: mul r2.xyzw, r0.wwww, r2.xyzw
  89: add r0.w, -cb0[13].w, cb0[13].z
  90: mad r0.w, r4.y, r0.w, cb0[13].w
  91: sample r3.xyzw, v1.zwzz, t3.xyzw, s2
  92: mad r3.xy, r3.wyww, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
  93: dp2 r1.w, r3.xyxx, r3.xyxx
  94: min r1.w, r1.w, l(1.000000)
  95: add r1.w, -r1.w, l(1.000000)
  96: sqrt r3.z, r1.w
  97: mad r3.xyz, r3.xyzx, r0.wwww, l(-0.000000, -0.000000, -1.000000, 0.000000)
  98: mad r3.xyz, r2.wwww, r3.xyzx, l(0.000000, 0.000000, 1.000000, 0.000000)
  99: add r1.xyz, r1.xyzx, -r3.xyzx
 100: dp3 r0.w, r1.xyzx, r1.xyzx
 101: rsq r0.w, r0.w
 102: mul r1.xyz, r0.wwww, r1.xyzx
 103: dp3 r3.x, v2.xyzx, -r1.xyzx
 104: dp3 r3.y, v3.xyzx, -r1.xyzx
 105: dp3 r3.z, v4.xyzx, -r1.xyzx
 106: dp3 r0.x, r3.xyzx, r0.xyzx
 107: max r0.x, r0.x, l(0.000000)
 108: log r0.x, r0.x
 109: add r0.y, -cb0[34].x, cb0[34].y
 110: mad r0.y, r4.y, r0.y, cb0[34].x
 111: mul r0.y, r0.y, l(128.000000)
 112: mul r0.x, r0.x, r0.y
 113: exp r0.x, r0.x
 114: mul r0.yzw, cb0[6].xxyz, cb0[7].xxyz
 115: mul r0.xyz, r0.xxxx, r0.yzwy
 116: dp3 r0.w, r3.xyzx, cb2[0].xyzx
 117: max r0.w, r0.w, l(0.000000)
 118: max r1.w, r2.w, l(0.000100)
 119: div r2.xyz, r2.xyzx, r1.wwww
 120: mul r4.xzw, r2.xxyz, cb0[6].xxyz
 121: mad r0.xyz, r4.xzwx, r0.wwww, r0.xyzx
 122: mov r3.w, l(1.000000)
 123: dp4 r5.x, cb2[38].xyzw, r3.xyzw
 124: dp4 r5.y, cb2[39].xyzw, r3.xyzw
 125: dp4 r5.z, cb2[40].xyzw, r3.xyzw
 126: add r3.xyz, r5.xyzx, v8.xyzx
 127: max r3.xyz, r3.xyzx, l(0.000000, 0.000000, 0.000000, 0.000000)
 128: log r4.xzw, r3.xxyz
 129: mul r4.xzw, r4.xxzw, l(0.416667, 0.000000, 0.416667, 0.416667)
 130: exp r4.xzw, r4.xxzw
 131: mad r4.xzw, r4.xxzw, l(1.055000, 0.000000, 1.055000, 1.055000), l(-0.055000, 0.000000, -0.055000, -0.055000)
 132: max r4.xzw, r4.xxzw, l(0.000000, 0.000000, 0.000000, 0.000000)
 133: eq r0.w, cb0[3].w, l(0.000000)
 134: movc r3.xyz, r0.wwww, r4.xzwx, r3.xyzx
 135: mad r0.xyz, r2.xyzx, r3.xyzx, r0.xyzx
 136: add r2.xyz, -cb0[14].xyzx, cb0[15].xyzx
 137: mad r2.xyz, r4.yyyy, r2.xyzx, cb0[14].xyzx
 138: mul r3.xyz, r1.yyyy, cb3[13].xyzx
 139: mad r1.xyw, cb3[12].xyxz, r1.xxxx, r3.xyxz
 140: mad r1.xyz, cb3[14].xyzx, r1.zzzz, r1.xywx
 141: dp3 r0.w, v7.xyzx, r1.xyzx
 142: add r0.w, r0.w, r0.w
 143: mad r1.xyz, r1.xyzx, -r0.wwww, v7.xyzx
 144: sample r1.xyzw, r1.xyzx, t4.xyzw, s3
 145: mul r1.xyz, r2.xyzx, r1.xyzx
 146: mad o0.xyz, r1.xyzx, r2.wwww, r0.xyzx
 147: mov o0.w, r2.w
 148: ret 
// Approximately 0 instruction slots used
"
}
}
 }


 // Stats for Vertex shader:
 //       d3d11 : 73 math
 //        d3d9 : 95 math
 //      opengl : 133 avg math (128..140), 9 avg texture (8..10), 2 branch
 // Stats for Fragment shader:
 //       d3d11 : 110 avg math (102..118), 9 avg texture (8..10)
 //        d3d9 : 145 avg math (137..152), 9 avg texture (8..10)
 Pass {
  Name "FORWARD"
  Tags { "LIGHTMODE"="ForwardAdd" "QUEUE"="Transparent" "IGNOREPROJECTOR"="true" "RenderType"="Transparent" }
  AlphaToMask On
  ZTest Less
  ZWrite Off
  Stencil {
   Ref 2
   ReadMask 1
   WriteMask 3
   Pass Replace
   ZFail Replace
  }
  Blend SrcAlpha One
  ColorMask RGB
  Offset 1, 1
  GpuProgramID 123191
Program "vp" {
SubProgram "opengl " {
// Stats: 134 math, 9 textures, 2 branches
Keywords { "POINT" }
"#version 120

#ifdef VERTEX
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _ScreenParams;

uniform mat4 _Object2World;
uniform mat4 _World2Object;
uniform vec4 unity_WorldTransformParams;

uniform float _FaceDilate;
uniform mat4 _EnvMatrix;
uniform float _WeightNormal;
uniform float _WeightBold;
uniform float _ScaleRatioA;
uniform float _VertexOffsetX;
uniform float _VertexOffsetY;
uniform float _GradientScale;
uniform float _ScaleX;
uniform float _ScaleY;
uniform float _PerspectiveFilter;
uniform vec4 _MainTex_ST;
uniform vec4 _FaceTex_ST;
attribute vec4 TANGENT;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec4 tmpvar_1;
  vec4 tmpvar_2;
  vec3 tmpvar_3;
  tmpvar_2.zw = gl_Vertex.zw;
  vec2 tmpvar_4;
  float scale_5;
  vec2 pixelSize_6;
  tmpvar_2.x = (gl_Vertex.x + _VertexOffsetX);
  tmpvar_2.y = (gl_Vertex.y + _VertexOffsetY);
  vec4 tmpvar_7;
  tmpvar_7.w = 1.0;
  tmpvar_7.xyz = _WorldSpaceCameraPos;
  tmpvar_3 = (gl_Normal * sign(dot (gl_Normal, 
    ((_World2Object * tmpvar_7).xyz - tmpvar_2.xyz)
  )));
  vec2 tmpvar_8;
  tmpvar_8.x = _ScaleX;
  tmpvar_8.y = _ScaleY;
  mat2 tmpvar_9;
  tmpvar_9[0] = gl_ProjectionMatrix[0].xy;
  tmpvar_9[1] = gl_ProjectionMatrix[1].xy;
  pixelSize_6 = ((gl_ModelViewProjectionMatrix * tmpvar_2).ww / (tmpvar_8 * (tmpvar_9 * _ScreenParams.xy)));
  scale_5 = (inversesqrt(dot (pixelSize_6, pixelSize_6)) * ((
    abs(gl_MultiTexCoord1.y)
   * _GradientScale) * 1.5));
  vec4 v_10;
  float tmpvar_11;
  tmpvar_11 = _World2Object[0].x;
  v_10.x = tmpvar_11;
  float tmpvar_12;
  tmpvar_12 = _World2Object[1].x;
  v_10.y = tmpvar_12;
  float tmpvar_13;
  tmpvar_13 = _World2Object[2].x;
  v_10.z = tmpvar_13;
  float tmpvar_14;
  tmpvar_14 = _World2Object[3].x;
  v_10.w = tmpvar_14;
  vec4 v_15;
  float tmpvar_16;
  tmpvar_16 = _World2Object[0].y;
  v_15.x = tmpvar_16;
  float tmpvar_17;
  tmpvar_17 = _World2Object[1].y;
  v_15.y = tmpvar_17;
  float tmpvar_18;
  tmpvar_18 = _World2Object[2].y;
  v_15.z = tmpvar_18;
  float tmpvar_19;
  tmpvar_19 = _World2Object[3].y;
  v_15.w = tmpvar_19;
  vec4 v_20;
  float tmpvar_21;
  tmpvar_21 = _World2Object[0].z;
  v_20.x = tmpvar_21;
  float tmpvar_22;
  tmpvar_22 = _World2Object[1].z;
  v_20.y = tmpvar_22;
  float tmpvar_23;
  tmpvar_23 = _World2Object[2].z;
  v_20.z = tmpvar_23;
  float tmpvar_24;
  tmpvar_24 = _World2Object[3].z;
  v_20.w = tmpvar_24;
  float tmpvar_25;
  tmpvar_25 = mix ((scale_5 * (1.0 - _PerspectiveFilter)), scale_5, abs(dot (
    normalize((((v_10.xyz * tmpvar_3.x) + (v_15.xyz * tmpvar_3.y)) + (v_20.xyz * tmpvar_3.z)))
  , 
    normalize((_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz))
  )));
  scale_5 = tmpvar_25;
  tmpvar_4.y = tmpvar_25;
  tmpvar_4.x = ((mix (_WeightNormal, _WeightBold, 
    float((0.0 >= gl_MultiTexCoord1.y))
  ) / _GradientScale) + ((_FaceDilate * _ScaleRatioA) * 0.5));
  vec2 tmpvar_26;
  tmpvar_26.x = ((floor(gl_MultiTexCoord1.x) * 5.0) / 4096.0);
  tmpvar_26.y = (fract(gl_MultiTexCoord1.x) * 5.0);
  mat3 tmpvar_27;
  tmpvar_27[0] = _EnvMatrix[0].xyz;
  tmpvar_27[1] = _EnvMatrix[1].xyz;
  tmpvar_27[2] = _EnvMatrix[2].xyz;
  tmpvar_1.xy = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  tmpvar_1.zw = ((tmpvar_26 * _FaceTex_ST.xy) + _FaceTex_ST.zw);
  vec4 v_28;
  v_28.x = tmpvar_11;
  v_28.y = tmpvar_12;
  v_28.z = tmpvar_13;
  v_28.w = tmpvar_14;
  vec4 v_29;
  v_29.x = tmpvar_16;
  v_29.y = tmpvar_17;
  v_29.z = tmpvar_18;
  v_29.w = tmpvar_19;
  vec4 v_30;
  v_30.x = tmpvar_21;
  v_30.y = tmpvar_22;
  v_30.z = tmpvar_23;
  v_30.w = tmpvar_24;
  vec3 tmpvar_31;
  tmpvar_31 = normalize(((
    (v_28.xyz * tmpvar_3.x)
   + 
    (v_29.xyz * tmpvar_3.y)
  ) + (v_30.xyz * tmpvar_3.z)));
  mat3 tmpvar_32;
  tmpvar_32[0] = _Object2World[0].xyz;
  tmpvar_32[1] = _Object2World[1].xyz;
  tmpvar_32[2] = _Object2World[2].xyz;
  vec3 tmpvar_33;
  tmpvar_33 = normalize((tmpvar_32 * TANGENT.xyz));
  vec3 tmpvar_34;
  tmpvar_34 = (((tmpvar_31.yzx * tmpvar_33.zxy) - (tmpvar_31.zxy * tmpvar_33.yzx)) * (TANGENT.w * unity_WorldTransformParams.w));
  vec3 tmpvar_35;
  tmpvar_35.x = tmpvar_33.x;
  tmpvar_35.y = tmpvar_34.x;
  tmpvar_35.z = tmpvar_31.x;
  vec3 tmpvar_36;
  tmpvar_36.x = tmpvar_33.y;
  tmpvar_36.y = tmpvar_34.y;
  tmpvar_36.z = tmpvar_31.y;
  vec3 tmpvar_37;
  tmpvar_37.x = tmpvar_33.z;
  tmpvar_37.y = tmpvar_34.z;
  tmpvar_37.z = tmpvar_31.z;
  gl_Position = (gl_ModelViewProjectionMatrix * tmpvar_2);
  xlv_TEXCOORD0 = tmpvar_1;
  xlv_TEXCOORD1 = tmpvar_35;
  xlv_TEXCOORD2 = tmpvar_36;
  xlv_TEXCOORD3 = tmpvar_37;
  xlv_TEXCOORD4 = (_Object2World * tmpvar_2).xyz;
  xlv_COLOR0 = gl_Color;
  xlv_TEXCOORD5 = tmpvar_4;
  xlv_TEXCOORD6 = (tmpvar_27 * (_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz));
}


#endif
#ifdef FRAGMENT
uniform vec4 _Time;
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _WorldSpaceLightPos0;
uniform vec4 _LightColor0;
uniform vec4 _SpecColor;
uniform sampler2D _LightTexture0;
uniform mat4 _LightMatrix0;
uniform sampler2D _FaceTex;
uniform float _FaceUVSpeedX;
uniform float _FaceUVSpeedY;
uniform vec4 _FaceColor;
uniform float _OutlineSoftness;
uniform sampler2D _OutlineTex;
uniform float _OutlineUVSpeedX;
uniform float _OutlineUVSpeedY;
uniform vec4 _OutlineColor;
uniform float _OutlineWidth;
uniform float _Bevel;
uniform float _BevelOffset;
uniform float _BevelWidth;
uniform float _BevelClamp;
uniform float _BevelRoundness;
uniform sampler2D _BumpMap;
uniform float _BumpOutline;
uniform float _BumpFace;
uniform float _ShaderFlags;
uniform float _ScaleRatioA;
uniform sampler2D _MainTex;
uniform float _TextureWidth;
uniform float _TextureHeight;
uniform float _GradientScale;
uniform float _FaceShininess;
uniform float _OutlineShininess;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
void main ()
{
  vec3 tmpvar_1;
  vec3 worldN_2;
  vec3 tmpvar_3;
  vec3 tmpvar_4;
  float tmpvar_5;
  float tmpvar_6;
  vec3 tmpvar_7;
  tmpvar_7 = normalize((_WorldSpaceLightPos0.xyz - xlv_TEXCOORD4));
  vec3 tmpvar_8;
  tmpvar_8 = normalize((_WorldSpaceCameraPos - xlv_TEXCOORD4));
  tmpvar_3 = vec3(0.0, 0.0, 0.0);
  tmpvar_6 = 0.0;
  tmpvar_5 = 0.0;
  vec3 tmpvar_9;
  vec3 tmpvar_10;
  float tmpvar_11;
  float tmpvar_12;
  tmpvar_9 = tmpvar_3;
  tmpvar_10 = tmpvar_4;
  tmpvar_11 = tmpvar_5;
  tmpvar_12 = tmpvar_6;
  vec3 bump_13;
  vec4 outlineColor_14;
  vec4 faceColor_15;
  vec3 tmpvar_16;
  tmpvar_16.z = 0.0;
  tmpvar_16.x = (1.0/(_TextureWidth));
  tmpvar_16.y = (1.0/(_TextureHeight));
  vec4 tmpvar_17;
  tmpvar_17.x = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.xz)).w;
  tmpvar_17.y = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.xz)).w;
  tmpvar_17.z = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.zy)).w;
  tmpvar_17.w = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.zy)).w;
  float tmpvar_18;
  tmpvar_18 = (((
    (0.5 - texture2D (_MainTex, xlv_TEXCOORD0.xy).w)
   - xlv_TEXCOORD5.x) * xlv_TEXCOORD5.y) + 0.5);
  float tmpvar_19;
  tmpvar_19 = ((_OutlineWidth * _ScaleRatioA) * xlv_TEXCOORD5.y);
  float tmpvar_20;
  tmpvar_20 = ((_OutlineSoftness * _ScaleRatioA) * xlv_TEXCOORD5.y);
  outlineColor_14.xyz = _OutlineColor.xyz;
  faceColor_15 = (_FaceColor * xlv_COLOR0);
  outlineColor_14.w = (_OutlineColor.w * xlv_COLOR0.w);
  vec2 tmpvar_21;
  tmpvar_21.x = (xlv_TEXCOORD0.z + (_FaceUVSpeedX * _Time.y));
  tmpvar_21.y = (xlv_TEXCOORD0.w + (_FaceUVSpeedY * _Time.y));
  faceColor_15 = (faceColor_15 * texture2D (_FaceTex, tmpvar_21));
  vec2 tmpvar_22;
  tmpvar_22.x = (xlv_TEXCOORD0.z + (_OutlineUVSpeedX * _Time.y));
  tmpvar_22.y = (xlv_TEXCOORD0.w + (_OutlineUVSpeedY * _Time.y));
  outlineColor_14 = (outlineColor_14 * texture2D (_OutlineTex, tmpvar_22));
  vec4 faceColor_23;
  faceColor_23.w = faceColor_15.w;
  vec4 outlineColor_24;
  outlineColor_24.w = outlineColor_14.w;
  faceColor_23.xyz = (faceColor_15.xyz * faceColor_15.w);
  outlineColor_24.xyz = (outlineColor_14.xyz * outlineColor_14.w);
  faceColor_23 = (mix (faceColor_23, outlineColor_24, vec4((
    clamp ((tmpvar_18 + (tmpvar_19 * 0.5)), 0.0, 1.0)
   * 
    sqrt(min (1.0, tmpvar_19))
  ))) * (1.0 - clamp (
    (((tmpvar_18 - (tmpvar_19 * 0.5)) + (tmpvar_20 * 0.5)) / (1.0 + tmpvar_20))
  , 0.0, 1.0)));
  faceColor_15.w = faceColor_23.w;
  faceColor_15.xyz = (faceColor_23.xyz / max (faceColor_23.w, 0.0001));
  vec4 h_25;
  h_25 = tmpvar_17;
  float tmpvar_26;
  tmpvar_26 = (_ShaderFlags / 2.0);
  float tmpvar_27;
  tmpvar_27 = (fract(abs(tmpvar_26)) * 2.0);
  float tmpvar_28;
  if ((tmpvar_26 >= 0.0)) {
    tmpvar_28 = tmpvar_27;
  } else {
    tmpvar_28 = -(tmpvar_27);
  };
  h_25 = (tmpvar_17 + (xlv_TEXCOORD5.x + _BevelOffset));
  float tmpvar_29;
  tmpvar_29 = max (0.01, (_OutlineWidth + _BevelWidth));
  h_25 = (h_25 - 0.5);
  h_25 = (h_25 / tmpvar_29);
  vec4 tmpvar_30;
  tmpvar_30 = clamp ((h_25 + 0.5), 0.0, 1.0);
  h_25 = tmpvar_30;
  if (bool(float((tmpvar_28 >= 1.0)))) {
    h_25 = (1.0 - abs((
      (tmpvar_30 * 2.0)
     - 1.0)));
  };
  h_25 = (min (mix (h_25, 
    sin(((h_25 * 3.141592) / 2.0))
  , vec4(_BevelRoundness)), vec4((1.0 - _BevelClamp))) * ((_Bevel * tmpvar_29) * (_GradientScale * -2.0)));
  vec3 tmpvar_31;
  tmpvar_31.xy = vec2(1.0, 0.0);
  tmpvar_31.z = (h_25.y - h_25.x);
  vec3 tmpvar_32;
  tmpvar_32 = normalize(tmpvar_31);
  vec3 tmpvar_33;
  tmpvar_33.xy = vec2(0.0, -1.0);
  tmpvar_33.z = (h_25.w - h_25.z);
  vec3 tmpvar_34;
  tmpvar_34 = normalize(tmpvar_33);
  vec3 normal_35;
  normal_35.xy = ((texture2D (_BumpMap, xlv_TEXCOORD0.zw).wy * 2.0) - 1.0);
  normal_35.z = sqrt((1.0 - clamp (
    dot (normal_35.xy, normal_35.xy)
  , 0.0, 1.0)));
  bump_13 = (normal_35 * mix (_BumpFace, _BumpOutline, clamp (
    (tmpvar_18 + (tmpvar_19 * 0.5))
  , 0.0, 1.0)));
  vec3 tmpvar_36;
  tmpvar_36 = mix (vec3(0.0, 0.0, 1.0), bump_13, faceColor_23.www);
  bump_13 = tmpvar_36;
  tmpvar_9 = faceColor_15.xyz;
  tmpvar_10 = -(normalize((
    ((tmpvar_32.yzx * tmpvar_34.zxy) - (tmpvar_32.zxy * tmpvar_34.yzx))
   - tmpvar_36)));
  tmpvar_11 = 1.0;
  tmpvar_12 = faceColor_15.w;
  tmpvar_3 = tmpvar_9;
  tmpvar_5 = tmpvar_11;
  tmpvar_6 = tmpvar_12;
  vec4 tmpvar_37;
  tmpvar_37.w = 1.0;
  tmpvar_37.xyz = xlv_TEXCOORD4;
  vec3 tmpvar_38;
  tmpvar_38 = (_LightMatrix0 * tmpvar_37).xyz;
  worldN_2.x = dot (xlv_TEXCOORD1, tmpvar_10);
  worldN_2.y = dot (xlv_TEXCOORD2, tmpvar_10);
  worldN_2.z = dot (xlv_TEXCOORD3, tmpvar_10);
  tmpvar_4 = worldN_2;
  tmpvar_1 = (_LightColor0.xyz * texture2D (_LightTexture0, vec2(dot (tmpvar_38, tmpvar_38))).w);
  vec4 c_39;
  vec4 c_40;
  c_40.xyz = (((faceColor_15.xyz * tmpvar_1) * max (0.0, 
    dot (worldN_2, tmpvar_7)
  )) + ((tmpvar_1 * _SpecColor.xyz) * pow (
    max (0.0, dot (worldN_2, normalize((tmpvar_7 + tmpvar_8))))
  , 
    (mix (_FaceShininess, _OutlineShininess, clamp ((tmpvar_18 + 
      (tmpvar_19 * 0.5)
    ), 0.0, 1.0)) * 128.0)
  )));
  c_40.w = tmpvar_12;
  c_39.w = c_40.w;
  c_39.xyz = c_40.xyz;
  gl_FragData[0] = c_39;
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 95 math
Keywords { "POINT" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
Matrix 10 [_EnvMatrix] 3
Matrix 4 [_Object2World] 3
Matrix 7 [_World2Object] 3
Matrix 0 [glstate_matrix_mvp]
Matrix 13 [glstate_matrix_projection] 2
Float 18 [_FaceDilate]
Vector 29 [_FaceTex_ST]
Float 24 [_GradientScale]
Vector 28 [_MainTex_ST]
Float 27 [_PerspectiveFilter]
Float 21 [_ScaleRatioA]
Float 25 [_ScaleX]
Float 26 [_ScaleY]
Vector 16 [_ScreenParams]
Float 22 [_VertexOffsetX]
Float 23 [_VertexOffsetY]
Float 20 [_WeightBold]
Float 19 [_WeightNormal]
Vector 15 [_WorldSpaceCameraPos]
Vector 17 [unity_WorldTransformParams]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   row_major float4x4 _EnvMatrix;
//   float _FaceDilate;
//   float4 _FaceTex_ST;
//   float _GradientScale;
//   float4 _MainTex_ST;
//   row_major float4x4 _Object2World;
//   float _PerspectiveFilter;
//   float _ScaleRatioA;
//   float _ScaleX;
//   float _ScaleY;
//   float4 _ScreenParams;
//   float _VertexOffsetX;
//   float _VertexOffsetY;
//   float _WeightBold;
//   float _WeightNormal;
//   row_major float4x4 _World2Object;
//   float3 _WorldSpaceCameraPos;
//   row_major float4x4 glstate_matrix_mvp;
//   row_major float4x4 glstate_matrix_projection;
//   float4 unity_WorldTransformParams;
//
//
// Registers:
//
//   Name                       Reg   Size
//   -------------------------- ----- ----
//   glstate_matrix_mvp         c0       4
//   _Object2World              c4       3
//   _World2Object              c7       3
//   _EnvMatrix                 c10      3
//   glstate_matrix_projection  c13      2
//   _WorldSpaceCameraPos       c15      1
//   _ScreenParams              c16      1
//   unity_WorldTransformParams c17      1
//   _FaceDilate                c18      1
//   _WeightNormal              c19      1
//   _WeightBold                c20      1
//   _ScaleRatioA               c21      1
//   _VertexOffsetX             c22      1
//   _VertexOffsetY             c23      1
//   _GradientScale             c24      1
//   _ScaleX                    c25      1
//   _ScaleY                    c26      1
//   _PerspectiveFilter         c27      1
//   _MainTex_ST                c28      1
//   _FaceTex_ST                c29      1
//

    vs_3_0
    def c30, 0, 1, 1.5, 0.5
    def c31, 0.00122070313, 5, 0, 0
    dcl_position v0
    dcl_tangent v1
    dcl_normal v2
    dcl_texcoord v3
    dcl_texcoord1 v4
    dcl_color v5
    dcl_position o0
    dcl_texcoord o1
    dcl_texcoord1 o2.xyz
    dcl_texcoord2 o3.xyz
    dcl_texcoord3 o4.xyz
    dcl_texcoord4 o5.xyz
    dcl_color o6
    dcl_texcoord5 o7.xy
    dcl_texcoord6 o8.xyz
    mov r0.xy, c30
    mad r1, c15.xyzx, r0.yyyx, r0.xxxy
    dp4 r2.x, c7, r1
    dp4 r2.y, c8, r1
    dp4 r2.z, c9, r1
    add r1.x, c22.x, v0.x
    add r1.y, c23.x, v0.y
    mov r1.zw, v0
    add r0.xzw, -r1.xyyz, r2.xyyz
    dp3 r0.x, v2, r0.xzww
    slt r0.z, -r0.x, r0.x
    slt r0.x, r0.x, -r0.x
    add r0.x, -r0.x, r0.z
    mul r0.xzw, r0.x, v2.xyyz
    mul r2.xyz, r0.z, c8.zxyw
    mad r2.xyz, c7.zxyw, r0.x, r2
    mad r0.xzw, c9.zyxy, r0.w, r2.xyyz
    dp3 r2.x, r0.xzww, r0.xzww
    rsq r2.x, r2.x
    mul r0.xzw, r0, r2.x
    dp4 r2.x, c4, r1
    dp4 r2.y, c5, r1
    dp4 r2.z, c6, r1
    add r3.xyz, -r2, c15
    mov o5.xyz, r2
    nrm r2.xyz, r3
    dp3 r2.x, r0.zwxw, r2
    mov r4.xy, c16
    mul r2.yz, r4.xxyw, c13.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c25.x
    rcp r5.x, r2.y
    mul r2.yz, r4.xxyw, c14.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c26.x
    rcp r5.y, r2.y
    dp4 r2.y, c3, r1
    mul r2.zw, r5.xyxy, r2.y
    mov o0.w, r2.y
    mul r2.yz, r2.xzww, r2.xzww
    add r2.y, r2.z, r2.y
    rsq r2.y, r2.y
    mul r2.z, c24.x, v4_abs.y
    mul r2.y, r2.y, r2.z
    mul r2.z, r2.y, c30.z
    add r0.y, r0.y, -c27.x
    mul r0.y, r0.y, r2.z
    mad r2.y, r2.y, c30.z, -r0.y
    mad o7.y, r2_abs.x, r2.y, r0.y
    sge r0.y, c30.x, v4.y
    mov r2.x, c19.x
    add r2.x, -r2.x, c20.x
    mad r0.y, r0.y, r2.x, c19.x
    mov r2.x, c18.x
    mul r2.x, r2.x, c21.x
    mul r2.x, r2.x, c30.w
    rcp r2.y, c24.x
    mad o7.x, r0.y, r2.y, r2.x
    dp3 o8.x, c10, r3
    dp3 o8.y, c11, r3
    dp3 o8.z, c12, r3
    dp4 o0.x, c0, r1
    dp4 o0.y, c1, r1
    dp4 o0.z, c2, r1
    mad o1.xy, v3, c28, c28.zwzw
    frc r0.y, v4.x
    add r1.x, -r0.y, v4.x
    mul r1.w, r0.y, c29.y
    mul r1.z, r1.x, c29.x
    mov r2.zw, c29
    mad o1.zw, r1, c31.xyxy, r2
    dp3 r1.z, c4, v1
    dp3 r1.x, c5, v1
    dp3 r1.y, c6, v1
    dp3 r0.y, r1, r1
    rsq r0.y, r0.y
    mul r1.xyz, r0.y, r1
    mov o2.x, r1.z
    mul r2.xyz, r0.xzww, r1
    mad r2.xyz, r0.wxzw, r1.yzxw, -r2
    mul r0.y, c17.w, v1.w
    mul r2.xyz, r0.y, r2
    mov o2.y, r2.x
    mov o2.z, r0.z
    mov o3.x, r1.x
    mov o4.x, r1.y
    mov o3.y, r2.y
    mov o4.y, r2.z
    mov o3.z, r0.w
    mov o4.z, r0.x
    mov o6, v5

// approximately 93 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 73 math
Keywords { "POINT" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
ConstBuffer "$Globals" 656
Matrix 336 [_EnvMatrix]
Float 224 [_FaceDilate]
Float 516 [_WeightNormal]
Float 520 [_WeightBold]
Float 524 [_ScaleRatioA]
Float 536 [_VertexOffsetX]
Float 540 [_VertexOffsetY]
Float 592 [_GradientScale]
Float 596 [_ScaleX]
Float 600 [_ScaleY]
Float 604 [_PerspectiveFilter]
Vector 624 [_MainTex_ST]
Vector 640 [_FaceTex_ST]
ConstBuffer "UnityPerCamera" 144
Vector 64 [_WorldSpaceCameraPos] 3
Vector 96 [_ScreenParams]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
Matrix 256 [_World2Object]
Vector 336 [unity_WorldTransformParams]
ConstBuffer "UnityPerFrame" 256
Matrix 0 [glstate_matrix_projection]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityPerDraw" 2
BindCB  "UnityPerFrame" 3
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// TANGENT                  0   xyzw        1     NONE   float   xyzw
// NORMAL                   0   xyz         2     NONE   float   xyz 
// TEXCOORD                 0   xyzw        3     NONE   float   xy  
// TEXCOORD                 1   xyzw        4     NONE   float   xy  
// TEXCOORD                 2   xyzw        5     NONE   float       
// TEXCOORD                 3   xyzw        6     NONE   float       
// COLOR                    0   xyzw        7     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float   xyz 
//
      vs_4_0
      dcl_constantbuffer cb0[41], immediateIndexed
      dcl_constantbuffer cb1[7], immediateIndexed
      dcl_constantbuffer cb2[22], immediateIndexed
      dcl_constantbuffer cb3[2], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v1.xyzw
      dcl_input v2.xyz
      dcl_input v3.xy
      dcl_input v4.xy
      dcl_input v7.xyzw
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xyzw
      dcl_output o2.xyz
      dcl_output o3.xyz
      dcl_output o4.xyz
      dcl_output o5.xyz
      dcl_output o6.xyzw
      dcl_output o7.xy
      dcl_output o8.xyz
      dcl_temps 4
   0: add r0.xy, v0.xyxx, cb0[33].zwzz
   1: mul r1.xyzw, r0.yyyy, cb2[1].xyzw
   2: mad r1.xyzw, cb2[0].xyzw, r0.xxxx, r1.xyzw
   3: mad r1.xyzw, cb2[2].xyzw, v0.zzzz, r1.xyzw
   4: mad o0.xyzw, cb2[3].xyzw, v0.wwww, r1.xyzw
   5: round_ni r0.w, v4.x
   6: mul r1.z, r0.w, cb0[40].x
   7: frc r0.w, v4.x
   8: mul r1.w, r0.w, cb0[40].y
   9: mad o1.zw, r1.zzzw, l(0.000000, 0.000000, 0.001221, 5.000000), cb0[40].zzzw
  10: mad o1.xy, v3.xyxx, cb0[39].xyxx, cb0[39].zwzz
  11: mul r1.xyz, cb1[4].yyyy, cb2[17].xyzx
  12: mad r1.xyz, cb2[16].xyzx, cb1[4].xxxx, r1.xyzx
  13: mad r1.xyz, cb2[18].xyzx, cb1[4].zzzz, r1.xyzx
  14: add r1.xyz, r1.xyzx, cb2[19].xyzx
  15: mov r0.z, v0.z
  16: add r1.xyz, -r0.xyzx, r1.xyzx
  17: dp3 r0.z, v2.xyzx, r1.xyzx
  18: lt r0.w, l(0.000000), r0.z
  19: lt r0.z, r0.z, l(0.000000)
  20: iadd r0.z, -r0.w, r0.z
  21: itof r0.z, r0.z
  22: mul r1.xyz, r0.zzzz, v2.xyzx
  23: mov r2.y, cb2[16].y
  24: mov r2.z, cb2[17].y
  25: mov r2.x, cb2[18].y
  26: mul r2.xyz, r1.yyyy, r2.xyzx
  27: mov r3.y, cb2[16].x
  28: mov r3.z, cb2[17].x
  29: mov r3.x, cb2[18].x
  30: mad r1.xyw, r3.xyxz, r1.xxxx, r2.xyxz
  31: mov r2.y, cb2[16].z
  32: mov r2.z, cb2[17].z
  33: mov r2.x, cb2[18].z
  34: mad r1.xyz, r2.xyzx, r1.zzzz, r1.xywx
  35: dp3 r0.z, r1.xyzx, r1.xyzx
  36: rsq r0.z, r0.z
  37: mul r1.xyz, r0.zzzz, r1.xyzx
  38: mov o2.z, r1.y
  39: mul r2.xyz, v1.yyyy, cb2[13].yzxy
  40: mad r2.xyz, cb2[12].yzxy, v1.xxxx, r2.xyzx
  41: mad r2.xyz, cb2[14].yzxy, v1.zzzz, r2.xyzx
  42: dp3 r0.z, r2.xyzx, r2.xyzx
  43: rsq r0.z, r0.z
  44: mul r2.xyz, r0.zzzz, r2.xyzx
  45: mul r3.xyz, r1.xyzx, r2.xyzx
  46: mad r3.xyz, r1.zxyz, r2.yzxy, -r3.xyzx
  47: mul r0.z, v1.w, cb2[21].w
  48: mul r3.xyz, r0.zzzz, r3.xyzx
  49: mov o2.y, r3.x
  50: mov o2.x, r2.z
  51: mov o3.x, r2.x
  52: mov o4.x, r2.y
  53: mov o3.z, r1.z
  54: mov o3.y, r3.y
  55: mov o4.y, r3.z
  56: mov o4.z, r1.x
  57: mul r2.xyz, r0.yyyy, cb2[13].xyzx
  58: mad r2.xyz, cb2[12].xyzx, r0.xxxx, r2.xyzx
  59: mad r2.xyz, cb2[14].xyzx, v0.zzzz, r2.xyzx
  60: mad r2.xyz, cb2[15].xyzx, v0.wwww, r2.xyzx
  61: mov o5.xyz, r2.xyzx
  62: add r2.xyz, -r2.xyzx, cb1[4].xyzx
  63: mov o6.xyzw, v7.xyzw
  64: mul r0.y, r0.y, cb2[1].w
  65: mad r0.x, cb2[0].w, r0.x, r0.y
  66: mad r0.x, cb2[2].w, v0.z, r0.x
  67: mad r0.x, cb2[3].w, v0.w, r0.x
  68: mul r0.yz, cb1[6].yyyy, cb3[1].xxyx
  69: mad r0.yz, cb3[0].xxyx, cb1[6].xxxx, r0.yyzy
  70: mul r0.yz, r0.yyzy, cb0[37].yyzy
  71: div r0.xy, r0.xxxx, r0.yzyy
  72: dp2 r0.x, r0.xyxx, r0.xyxx
  73: rsq r0.x, r0.x
  74: mul r0.y, |v4.y|, cb0[37].x
  75: mul r0.x, r0.x, r0.y
  76: mul r0.y, r0.x, l(1.500000)
  77: add r0.z, -cb0[37].w, l(1.000000)
  78: mul r0.y, r0.z, r0.y
  79: mad r0.x, r0.x, l(1.500000), -r0.y
  80: dp3 r0.z, r2.xyzx, r2.xyzx
  81: rsq r0.z, r0.z
  82: mul r3.xyz, r0.zzzz, r2.xyzx
  83: dp3 r0.z, r1.yzxy, r3.xyzx
  84: mad o7.y, |r0.z|, r0.x, r0.y
  85: ge r0.x, l(0.000000), v4.y
  86: and r0.x, r0.x, l(0x3f800000)
  87: add r0.y, -cb0[32].y, cb0[32].z
  88: mad r0.x, r0.x, r0.y, cb0[32].y
  89: div r0.x, r0.x, cb0[37].x
  90: mul r0.y, cb0[14].x, cb0[32].w
  91: mad o7.x, r0.y, l(0.500000), r0.x
  92: mul r0.xyz, r2.yyyy, cb0[22].xyzx
  93: mad r0.xyz, cb0[21].xyzx, r2.xxxx, r0.xyzx
  94: mad o8.xyz, cb0[23].xyzx, r2.zzzz, r0.xyzx
  95: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
// Stats: 128 math, 8 textures, 2 branches
Keywords { "DIRECTIONAL" }
"#version 120

#ifdef VERTEX
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _ScreenParams;

uniform mat4 _Object2World;
uniform mat4 _World2Object;
uniform vec4 unity_WorldTransformParams;

uniform float _FaceDilate;
uniform mat4 _EnvMatrix;
uniform float _WeightNormal;
uniform float _WeightBold;
uniform float _ScaleRatioA;
uniform float _VertexOffsetX;
uniform float _VertexOffsetY;
uniform float _GradientScale;
uniform float _ScaleX;
uniform float _ScaleY;
uniform float _PerspectiveFilter;
uniform vec4 _MainTex_ST;
uniform vec4 _FaceTex_ST;
attribute vec4 TANGENT;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec4 tmpvar_1;
  vec4 tmpvar_2;
  vec3 tmpvar_3;
  tmpvar_2.zw = gl_Vertex.zw;
  vec2 tmpvar_4;
  float scale_5;
  vec2 pixelSize_6;
  tmpvar_2.x = (gl_Vertex.x + _VertexOffsetX);
  tmpvar_2.y = (gl_Vertex.y + _VertexOffsetY);
  vec4 tmpvar_7;
  tmpvar_7.w = 1.0;
  tmpvar_7.xyz = _WorldSpaceCameraPos;
  tmpvar_3 = (gl_Normal * sign(dot (gl_Normal, 
    ((_World2Object * tmpvar_7).xyz - tmpvar_2.xyz)
  )));
  vec2 tmpvar_8;
  tmpvar_8.x = _ScaleX;
  tmpvar_8.y = _ScaleY;
  mat2 tmpvar_9;
  tmpvar_9[0] = gl_ProjectionMatrix[0].xy;
  tmpvar_9[1] = gl_ProjectionMatrix[1].xy;
  pixelSize_6 = ((gl_ModelViewProjectionMatrix * tmpvar_2).ww / (tmpvar_8 * (tmpvar_9 * _ScreenParams.xy)));
  scale_5 = (inversesqrt(dot (pixelSize_6, pixelSize_6)) * ((
    abs(gl_MultiTexCoord1.y)
   * _GradientScale) * 1.5));
  vec4 v_10;
  float tmpvar_11;
  tmpvar_11 = _World2Object[0].x;
  v_10.x = tmpvar_11;
  float tmpvar_12;
  tmpvar_12 = _World2Object[1].x;
  v_10.y = tmpvar_12;
  float tmpvar_13;
  tmpvar_13 = _World2Object[2].x;
  v_10.z = tmpvar_13;
  float tmpvar_14;
  tmpvar_14 = _World2Object[3].x;
  v_10.w = tmpvar_14;
  vec4 v_15;
  float tmpvar_16;
  tmpvar_16 = _World2Object[0].y;
  v_15.x = tmpvar_16;
  float tmpvar_17;
  tmpvar_17 = _World2Object[1].y;
  v_15.y = tmpvar_17;
  float tmpvar_18;
  tmpvar_18 = _World2Object[2].y;
  v_15.z = tmpvar_18;
  float tmpvar_19;
  tmpvar_19 = _World2Object[3].y;
  v_15.w = tmpvar_19;
  vec4 v_20;
  float tmpvar_21;
  tmpvar_21 = _World2Object[0].z;
  v_20.x = tmpvar_21;
  float tmpvar_22;
  tmpvar_22 = _World2Object[1].z;
  v_20.y = tmpvar_22;
  float tmpvar_23;
  tmpvar_23 = _World2Object[2].z;
  v_20.z = tmpvar_23;
  float tmpvar_24;
  tmpvar_24 = _World2Object[3].z;
  v_20.w = tmpvar_24;
  float tmpvar_25;
  tmpvar_25 = mix ((scale_5 * (1.0 - _PerspectiveFilter)), scale_5, abs(dot (
    normalize((((v_10.xyz * tmpvar_3.x) + (v_15.xyz * tmpvar_3.y)) + (v_20.xyz * tmpvar_3.z)))
  , 
    normalize((_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz))
  )));
  scale_5 = tmpvar_25;
  tmpvar_4.y = tmpvar_25;
  tmpvar_4.x = ((mix (_WeightNormal, _WeightBold, 
    float((0.0 >= gl_MultiTexCoord1.y))
  ) / _GradientScale) + ((_FaceDilate * _ScaleRatioA) * 0.5));
  vec2 tmpvar_26;
  tmpvar_26.x = ((floor(gl_MultiTexCoord1.x) * 5.0) / 4096.0);
  tmpvar_26.y = (fract(gl_MultiTexCoord1.x) * 5.0);
  mat3 tmpvar_27;
  tmpvar_27[0] = _EnvMatrix[0].xyz;
  tmpvar_27[1] = _EnvMatrix[1].xyz;
  tmpvar_27[2] = _EnvMatrix[2].xyz;
  tmpvar_1.xy = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  tmpvar_1.zw = ((tmpvar_26 * _FaceTex_ST.xy) + _FaceTex_ST.zw);
  vec4 v_28;
  v_28.x = tmpvar_11;
  v_28.y = tmpvar_12;
  v_28.z = tmpvar_13;
  v_28.w = tmpvar_14;
  vec4 v_29;
  v_29.x = tmpvar_16;
  v_29.y = tmpvar_17;
  v_29.z = tmpvar_18;
  v_29.w = tmpvar_19;
  vec4 v_30;
  v_30.x = tmpvar_21;
  v_30.y = tmpvar_22;
  v_30.z = tmpvar_23;
  v_30.w = tmpvar_24;
  vec3 tmpvar_31;
  tmpvar_31 = normalize(((
    (v_28.xyz * tmpvar_3.x)
   + 
    (v_29.xyz * tmpvar_3.y)
  ) + (v_30.xyz * tmpvar_3.z)));
  mat3 tmpvar_32;
  tmpvar_32[0] = _Object2World[0].xyz;
  tmpvar_32[1] = _Object2World[1].xyz;
  tmpvar_32[2] = _Object2World[2].xyz;
  vec3 tmpvar_33;
  tmpvar_33 = normalize((tmpvar_32 * TANGENT.xyz));
  vec3 tmpvar_34;
  tmpvar_34 = (((tmpvar_31.yzx * tmpvar_33.zxy) - (tmpvar_31.zxy * tmpvar_33.yzx)) * (TANGENT.w * unity_WorldTransformParams.w));
  vec3 tmpvar_35;
  tmpvar_35.x = tmpvar_33.x;
  tmpvar_35.y = tmpvar_34.x;
  tmpvar_35.z = tmpvar_31.x;
  vec3 tmpvar_36;
  tmpvar_36.x = tmpvar_33.y;
  tmpvar_36.y = tmpvar_34.y;
  tmpvar_36.z = tmpvar_31.y;
  vec3 tmpvar_37;
  tmpvar_37.x = tmpvar_33.z;
  tmpvar_37.y = tmpvar_34.z;
  tmpvar_37.z = tmpvar_31.z;
  gl_Position = (gl_ModelViewProjectionMatrix * tmpvar_2);
  xlv_TEXCOORD0 = tmpvar_1;
  xlv_TEXCOORD1 = tmpvar_35;
  xlv_TEXCOORD2 = tmpvar_36;
  xlv_TEXCOORD3 = tmpvar_37;
  xlv_TEXCOORD4 = (_Object2World * tmpvar_2).xyz;
  xlv_COLOR0 = gl_Color;
  xlv_TEXCOORD5 = tmpvar_4;
  xlv_TEXCOORD6 = (tmpvar_27 * (_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz));
}


#endif
#ifdef FRAGMENT
uniform vec4 _Time;
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _WorldSpaceLightPos0;
uniform vec4 _LightColor0;
uniform vec4 _SpecColor;
uniform sampler2D _FaceTex;
uniform float _FaceUVSpeedX;
uniform float _FaceUVSpeedY;
uniform vec4 _FaceColor;
uniform float _OutlineSoftness;
uniform sampler2D _OutlineTex;
uniform float _OutlineUVSpeedX;
uniform float _OutlineUVSpeedY;
uniform vec4 _OutlineColor;
uniform float _OutlineWidth;
uniform float _Bevel;
uniform float _BevelOffset;
uniform float _BevelWidth;
uniform float _BevelClamp;
uniform float _BevelRoundness;
uniform sampler2D _BumpMap;
uniform float _BumpOutline;
uniform float _BumpFace;
uniform float _ShaderFlags;
uniform float _ScaleRatioA;
uniform sampler2D _MainTex;
uniform float _TextureWidth;
uniform float _TextureHeight;
uniform float _GradientScale;
uniform float _FaceShininess;
uniform float _OutlineShininess;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
void main ()
{
  vec3 worldN_1;
  vec3 tmpvar_2;
  vec3 tmpvar_3;
  float tmpvar_4;
  float tmpvar_5;
  vec3 tmpvar_6;
  tmpvar_6 = normalize((_WorldSpaceCameraPos - xlv_TEXCOORD4));
  tmpvar_2 = vec3(0.0, 0.0, 0.0);
  tmpvar_5 = 0.0;
  tmpvar_4 = 0.0;
  vec3 tmpvar_7;
  vec3 tmpvar_8;
  float tmpvar_9;
  float tmpvar_10;
  tmpvar_7 = tmpvar_2;
  tmpvar_8 = tmpvar_3;
  tmpvar_9 = tmpvar_4;
  tmpvar_10 = tmpvar_5;
  vec3 bump_11;
  vec4 outlineColor_12;
  vec4 faceColor_13;
  vec3 tmpvar_14;
  tmpvar_14.z = 0.0;
  tmpvar_14.x = (1.0/(_TextureWidth));
  tmpvar_14.y = (1.0/(_TextureHeight));
  vec4 tmpvar_15;
  tmpvar_15.x = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_14.xz)).w;
  tmpvar_15.y = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_14.xz)).w;
  tmpvar_15.z = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_14.zy)).w;
  tmpvar_15.w = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_14.zy)).w;
  float tmpvar_16;
  tmpvar_16 = (((
    (0.5 - texture2D (_MainTex, xlv_TEXCOORD0.xy).w)
   - xlv_TEXCOORD5.x) * xlv_TEXCOORD5.y) + 0.5);
  float tmpvar_17;
  tmpvar_17 = ((_OutlineWidth * _ScaleRatioA) * xlv_TEXCOORD5.y);
  float tmpvar_18;
  tmpvar_18 = ((_OutlineSoftness * _ScaleRatioA) * xlv_TEXCOORD5.y);
  outlineColor_12.xyz = _OutlineColor.xyz;
  faceColor_13 = (_FaceColor * xlv_COLOR0);
  outlineColor_12.w = (_OutlineColor.w * xlv_COLOR0.w);
  vec2 tmpvar_19;
  tmpvar_19.x = (xlv_TEXCOORD0.z + (_FaceUVSpeedX * _Time.y));
  tmpvar_19.y = (xlv_TEXCOORD0.w + (_FaceUVSpeedY * _Time.y));
  faceColor_13 = (faceColor_13 * texture2D (_FaceTex, tmpvar_19));
  vec2 tmpvar_20;
  tmpvar_20.x = (xlv_TEXCOORD0.z + (_OutlineUVSpeedX * _Time.y));
  tmpvar_20.y = (xlv_TEXCOORD0.w + (_OutlineUVSpeedY * _Time.y));
  outlineColor_12 = (outlineColor_12 * texture2D (_OutlineTex, tmpvar_20));
  vec4 faceColor_21;
  faceColor_21.w = faceColor_13.w;
  vec4 outlineColor_22;
  outlineColor_22.w = outlineColor_12.w;
  faceColor_21.xyz = (faceColor_13.xyz * faceColor_13.w);
  outlineColor_22.xyz = (outlineColor_12.xyz * outlineColor_12.w);
  faceColor_21 = (mix (faceColor_21, outlineColor_22, vec4((
    clamp ((tmpvar_16 + (tmpvar_17 * 0.5)), 0.0, 1.0)
   * 
    sqrt(min (1.0, tmpvar_17))
  ))) * (1.0 - clamp (
    (((tmpvar_16 - (tmpvar_17 * 0.5)) + (tmpvar_18 * 0.5)) / (1.0 + tmpvar_18))
  , 0.0, 1.0)));
  faceColor_13.w = faceColor_21.w;
  faceColor_13.xyz = (faceColor_21.xyz / max (faceColor_21.w, 0.0001));
  vec4 h_23;
  h_23 = tmpvar_15;
  float tmpvar_24;
  tmpvar_24 = (_ShaderFlags / 2.0);
  float tmpvar_25;
  tmpvar_25 = (fract(abs(tmpvar_24)) * 2.0);
  float tmpvar_26;
  if ((tmpvar_24 >= 0.0)) {
    tmpvar_26 = tmpvar_25;
  } else {
    tmpvar_26 = -(tmpvar_25);
  };
  h_23 = (tmpvar_15 + (xlv_TEXCOORD5.x + _BevelOffset));
  float tmpvar_27;
  tmpvar_27 = max (0.01, (_OutlineWidth + _BevelWidth));
  h_23 = (h_23 - 0.5);
  h_23 = (h_23 / tmpvar_27);
  vec4 tmpvar_28;
  tmpvar_28 = clamp ((h_23 + 0.5), 0.0, 1.0);
  h_23 = tmpvar_28;
  if (bool(float((tmpvar_26 >= 1.0)))) {
    h_23 = (1.0 - abs((
      (tmpvar_28 * 2.0)
     - 1.0)));
  };
  h_23 = (min (mix (h_23, 
    sin(((h_23 * 3.141592) / 2.0))
  , vec4(_BevelRoundness)), vec4((1.0 - _BevelClamp))) * ((_Bevel * tmpvar_27) * (_GradientScale * -2.0)));
  vec3 tmpvar_29;
  tmpvar_29.xy = vec2(1.0, 0.0);
  tmpvar_29.z = (h_23.y - h_23.x);
  vec3 tmpvar_30;
  tmpvar_30 = normalize(tmpvar_29);
  vec3 tmpvar_31;
  tmpvar_31.xy = vec2(0.0, -1.0);
  tmpvar_31.z = (h_23.w - h_23.z);
  vec3 tmpvar_32;
  tmpvar_32 = normalize(tmpvar_31);
  vec3 normal_33;
  normal_33.xy = ((texture2D (_BumpMap, xlv_TEXCOORD0.zw).wy * 2.0) - 1.0);
  normal_33.z = sqrt((1.0 - clamp (
    dot (normal_33.xy, normal_33.xy)
  , 0.0, 1.0)));
  bump_11 = (normal_33 * mix (_BumpFace, _BumpOutline, clamp (
    (tmpvar_16 + (tmpvar_17 * 0.5))
  , 0.0, 1.0)));
  vec3 tmpvar_34;
  tmpvar_34 = mix (vec3(0.0, 0.0, 1.0), bump_11, faceColor_21.www);
  bump_11 = tmpvar_34;
  tmpvar_7 = faceColor_13.xyz;
  tmpvar_8 = -(normalize((
    ((tmpvar_30.yzx * tmpvar_32.zxy) - (tmpvar_30.zxy * tmpvar_32.yzx))
   - tmpvar_34)));
  tmpvar_9 = 1.0;
  tmpvar_10 = faceColor_13.w;
  tmpvar_2 = tmpvar_7;
  tmpvar_4 = tmpvar_9;
  tmpvar_5 = tmpvar_10;
  worldN_1.x = dot (xlv_TEXCOORD1, tmpvar_8);
  worldN_1.y = dot (xlv_TEXCOORD2, tmpvar_8);
  worldN_1.z = dot (xlv_TEXCOORD3, tmpvar_8);
  tmpvar_3 = worldN_1;
  vec4 c_35;
  vec4 c_36;
  c_36.xyz = (((faceColor_13.xyz * _LightColor0.xyz) * max (0.0, 
    dot (worldN_1, _WorldSpaceLightPos0.xyz)
  )) + ((_LightColor0.xyz * _SpecColor.xyz) * pow (
    max (0.0, dot (worldN_1, normalize((_WorldSpaceLightPos0.xyz + tmpvar_6))))
  , 
    (mix (_FaceShininess, _OutlineShininess, clamp ((tmpvar_16 + 
      (tmpvar_17 * 0.5)
    ), 0.0, 1.0)) * 128.0)
  )));
  c_36.w = tmpvar_10;
  c_35.w = c_36.w;
  c_35.xyz = c_36.xyz;
  gl_FragData[0] = c_35;
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 95 math
Keywords { "DIRECTIONAL" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
Matrix 10 [_EnvMatrix] 3
Matrix 4 [_Object2World] 3
Matrix 7 [_World2Object] 3
Matrix 0 [glstate_matrix_mvp]
Matrix 13 [glstate_matrix_projection] 2
Float 18 [_FaceDilate]
Vector 29 [_FaceTex_ST]
Float 24 [_GradientScale]
Vector 28 [_MainTex_ST]
Float 27 [_PerspectiveFilter]
Float 21 [_ScaleRatioA]
Float 25 [_ScaleX]
Float 26 [_ScaleY]
Vector 16 [_ScreenParams]
Float 22 [_VertexOffsetX]
Float 23 [_VertexOffsetY]
Float 20 [_WeightBold]
Float 19 [_WeightNormal]
Vector 15 [_WorldSpaceCameraPos]
Vector 17 [unity_WorldTransformParams]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   row_major float4x4 _EnvMatrix;
//   float _FaceDilate;
//   float4 _FaceTex_ST;
//   float _GradientScale;
//   float4 _MainTex_ST;
//   row_major float4x4 _Object2World;
//   float _PerspectiveFilter;
//   float _ScaleRatioA;
//   float _ScaleX;
//   float _ScaleY;
//   float4 _ScreenParams;
//   float _VertexOffsetX;
//   float _VertexOffsetY;
//   float _WeightBold;
//   float _WeightNormal;
//   row_major float4x4 _World2Object;
//   float3 _WorldSpaceCameraPos;
//   row_major float4x4 glstate_matrix_mvp;
//   row_major float4x4 glstate_matrix_projection;
//   float4 unity_WorldTransformParams;
//
//
// Registers:
//
//   Name                       Reg   Size
//   -------------------------- ----- ----
//   glstate_matrix_mvp         c0       4
//   _Object2World              c4       3
//   _World2Object              c7       3
//   _EnvMatrix                 c10      3
//   glstate_matrix_projection  c13      2
//   _WorldSpaceCameraPos       c15      1
//   _ScreenParams              c16      1
//   unity_WorldTransformParams c17      1
//   _FaceDilate                c18      1
//   _WeightNormal              c19      1
//   _WeightBold                c20      1
//   _ScaleRatioA               c21      1
//   _VertexOffsetX             c22      1
//   _VertexOffsetY             c23      1
//   _GradientScale             c24      1
//   _ScaleX                    c25      1
//   _ScaleY                    c26      1
//   _PerspectiveFilter         c27      1
//   _MainTex_ST                c28      1
//   _FaceTex_ST                c29      1
//

    vs_3_0
    def c30, 0, 1, 1.5, 0.5
    def c31, 0.00122070313, 5, 0, 0
    dcl_position v0
    dcl_tangent v1
    dcl_normal v2
    dcl_texcoord v3
    dcl_texcoord1 v4
    dcl_color v5
    dcl_position o0
    dcl_texcoord o1
    dcl_texcoord1 o2.xyz
    dcl_texcoord2 o3.xyz
    dcl_texcoord3 o4.xyz
    dcl_texcoord4 o5.xyz
    dcl_color o6
    dcl_texcoord5 o7.xy
    dcl_texcoord6 o8.xyz
    mov r0.xy, c30
    mad r1, c15.xyzx, r0.yyyx, r0.xxxy
    dp4 r2.x, c7, r1
    dp4 r2.y, c8, r1
    dp4 r2.z, c9, r1
    add r1.x, c22.x, v0.x
    add r1.y, c23.x, v0.y
    mov r1.zw, v0
    add r0.xzw, -r1.xyyz, r2.xyyz
    dp3 r0.x, v2, r0.xzww
    slt r0.z, -r0.x, r0.x
    slt r0.x, r0.x, -r0.x
    add r0.x, -r0.x, r0.z
    mul r0.xzw, r0.x, v2.xyyz
    mul r2.xyz, r0.z, c8.zxyw
    mad r2.xyz, c7.zxyw, r0.x, r2
    mad r0.xzw, c9.zyxy, r0.w, r2.xyyz
    dp3 r2.x, r0.xzww, r0.xzww
    rsq r2.x, r2.x
    mul r0.xzw, r0, r2.x
    dp4 r2.x, c4, r1
    dp4 r2.y, c5, r1
    dp4 r2.z, c6, r1
    add r3.xyz, -r2, c15
    mov o5.xyz, r2
    nrm r2.xyz, r3
    dp3 r2.x, r0.zwxw, r2
    mov r4.xy, c16
    mul r2.yz, r4.xxyw, c13.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c25.x
    rcp r5.x, r2.y
    mul r2.yz, r4.xxyw, c14.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c26.x
    rcp r5.y, r2.y
    dp4 r2.y, c3, r1
    mul r2.zw, r5.xyxy, r2.y
    mov o0.w, r2.y
    mul r2.yz, r2.xzww, r2.xzww
    add r2.y, r2.z, r2.y
    rsq r2.y, r2.y
    mul r2.z, c24.x, v4_abs.y
    mul r2.y, r2.y, r2.z
    mul r2.z, r2.y, c30.z
    add r0.y, r0.y, -c27.x
    mul r0.y, r0.y, r2.z
    mad r2.y, r2.y, c30.z, -r0.y
    mad o7.y, r2_abs.x, r2.y, r0.y
    sge r0.y, c30.x, v4.y
    mov r2.x, c19.x
    add r2.x, -r2.x, c20.x
    mad r0.y, r0.y, r2.x, c19.x
    mov r2.x, c18.x
    mul r2.x, r2.x, c21.x
    mul r2.x, r2.x, c30.w
    rcp r2.y, c24.x
    mad o7.x, r0.y, r2.y, r2.x
    dp3 o8.x, c10, r3
    dp3 o8.y, c11, r3
    dp3 o8.z, c12, r3
    dp4 o0.x, c0, r1
    dp4 o0.y, c1, r1
    dp4 o0.z, c2, r1
    mad o1.xy, v3, c28, c28.zwzw
    frc r0.y, v4.x
    add r1.x, -r0.y, v4.x
    mul r1.w, r0.y, c29.y
    mul r1.z, r1.x, c29.x
    mov r2.zw, c29
    mad o1.zw, r1, c31.xyxy, r2
    dp3 r1.z, c4, v1
    dp3 r1.x, c5, v1
    dp3 r1.y, c6, v1
    dp3 r0.y, r1, r1
    rsq r0.y, r0.y
    mul r1.xyz, r0.y, r1
    mov o2.x, r1.z
    mul r2.xyz, r0.xzww, r1
    mad r2.xyz, r0.wxzw, r1.yzxw, -r2
    mul r0.y, c17.w, v1.w
    mul r2.xyz, r0.y, r2
    mov o2.y, r2.x
    mov o2.z, r0.z
    mov o3.x, r1.x
    mov o4.x, r1.y
    mov o3.y, r2.y
    mov o4.y, r2.z
    mov o3.z, r0.w
    mov o4.z, r0.x
    mov o6, v5

// approximately 93 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 73 math
Keywords { "DIRECTIONAL" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
ConstBuffer "$Globals" 592
Matrix 272 [_EnvMatrix]
Float 160 [_FaceDilate]
Float 452 [_WeightNormal]
Float 456 [_WeightBold]
Float 460 [_ScaleRatioA]
Float 472 [_VertexOffsetX]
Float 476 [_VertexOffsetY]
Float 528 [_GradientScale]
Float 532 [_ScaleX]
Float 536 [_ScaleY]
Float 540 [_PerspectiveFilter]
Vector 560 [_MainTex_ST]
Vector 576 [_FaceTex_ST]
ConstBuffer "UnityPerCamera" 144
Vector 64 [_WorldSpaceCameraPos] 3
Vector 96 [_ScreenParams]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
Matrix 256 [_World2Object]
Vector 336 [unity_WorldTransformParams]
ConstBuffer "UnityPerFrame" 256
Matrix 0 [glstate_matrix_projection]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityPerDraw" 2
BindCB  "UnityPerFrame" 3
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// TANGENT                  0   xyzw        1     NONE   float   xyzw
// NORMAL                   0   xyz         2     NONE   float   xyz 
// TEXCOORD                 0   xyzw        3     NONE   float   xy  
// TEXCOORD                 1   xyzw        4     NONE   float   xy  
// TEXCOORD                 2   xyzw        5     NONE   float       
// TEXCOORD                 3   xyzw        6     NONE   float       
// COLOR                    0   xyzw        7     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float   xyz 
//
      vs_4_0
      dcl_constantbuffer cb0[37], immediateIndexed
      dcl_constantbuffer cb1[7], immediateIndexed
      dcl_constantbuffer cb2[22], immediateIndexed
      dcl_constantbuffer cb3[2], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v1.xyzw
      dcl_input v2.xyz
      dcl_input v3.xy
      dcl_input v4.xy
      dcl_input v7.xyzw
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xyzw
      dcl_output o2.xyz
      dcl_output o3.xyz
      dcl_output o4.xyz
      dcl_output o5.xyz
      dcl_output o6.xyzw
      dcl_output o7.xy
      dcl_output o8.xyz
      dcl_temps 4
   0: add r0.xy, v0.xyxx, cb0[29].zwzz
   1: mul r1.xyzw, r0.yyyy, cb2[1].xyzw
   2: mad r1.xyzw, cb2[0].xyzw, r0.xxxx, r1.xyzw
   3: mad r1.xyzw, cb2[2].xyzw, v0.zzzz, r1.xyzw
   4: mad o0.xyzw, cb2[3].xyzw, v0.wwww, r1.xyzw
   5: round_ni r0.w, v4.x
   6: mul r1.z, r0.w, cb0[36].x
   7: frc r0.w, v4.x
   8: mul r1.w, r0.w, cb0[36].y
   9: mad o1.zw, r1.zzzw, l(0.000000, 0.000000, 0.001221, 5.000000), cb0[36].zzzw
  10: mad o1.xy, v3.xyxx, cb0[35].xyxx, cb0[35].zwzz
  11: mul r1.xyz, cb1[4].yyyy, cb2[17].xyzx
  12: mad r1.xyz, cb2[16].xyzx, cb1[4].xxxx, r1.xyzx
  13: mad r1.xyz, cb2[18].xyzx, cb1[4].zzzz, r1.xyzx
  14: add r1.xyz, r1.xyzx, cb2[19].xyzx
  15: mov r0.z, v0.z
  16: add r1.xyz, -r0.xyzx, r1.xyzx
  17: dp3 r0.z, v2.xyzx, r1.xyzx
  18: lt r0.w, l(0.000000), r0.z
  19: lt r0.z, r0.z, l(0.000000)
  20: iadd r0.z, -r0.w, r0.z
  21: itof r0.z, r0.z
  22: mul r1.xyz, r0.zzzz, v2.xyzx
  23: mov r2.y, cb2[16].y
  24: mov r2.z, cb2[17].y
  25: mov r2.x, cb2[18].y
  26: mul r2.xyz, r1.yyyy, r2.xyzx
  27: mov r3.y, cb2[16].x
  28: mov r3.z, cb2[17].x
  29: mov r3.x, cb2[18].x
  30: mad r1.xyw, r3.xyxz, r1.xxxx, r2.xyxz
  31: mov r2.y, cb2[16].z
  32: mov r2.z, cb2[17].z
  33: mov r2.x, cb2[18].z
  34: mad r1.xyz, r2.xyzx, r1.zzzz, r1.xywx
  35: dp3 r0.z, r1.xyzx, r1.xyzx
  36: rsq r0.z, r0.z
  37: mul r1.xyz, r0.zzzz, r1.xyzx
  38: mov o2.z, r1.y
  39: mul r2.xyz, v1.yyyy, cb2[13].yzxy
  40: mad r2.xyz, cb2[12].yzxy, v1.xxxx, r2.xyzx
  41: mad r2.xyz, cb2[14].yzxy, v1.zzzz, r2.xyzx
  42: dp3 r0.z, r2.xyzx, r2.xyzx
  43: rsq r0.z, r0.z
  44: mul r2.xyz, r0.zzzz, r2.xyzx
  45: mul r3.xyz, r1.xyzx, r2.xyzx
  46: mad r3.xyz, r1.zxyz, r2.yzxy, -r3.xyzx
  47: mul r0.z, v1.w, cb2[21].w
  48: mul r3.xyz, r0.zzzz, r3.xyzx
  49: mov o2.y, r3.x
  50: mov o2.x, r2.z
  51: mov o3.x, r2.x
  52: mov o4.x, r2.y
  53: mov o3.z, r1.z
  54: mov o3.y, r3.y
  55: mov o4.y, r3.z
  56: mov o4.z, r1.x
  57: mul r2.xyz, r0.yyyy, cb2[13].xyzx
  58: mad r2.xyz, cb2[12].xyzx, r0.xxxx, r2.xyzx
  59: mad r2.xyz, cb2[14].xyzx, v0.zzzz, r2.xyzx
  60: mad r2.xyz, cb2[15].xyzx, v0.wwww, r2.xyzx
  61: mov o5.xyz, r2.xyzx
  62: add r2.xyz, -r2.xyzx, cb1[4].xyzx
  63: mov o6.xyzw, v7.xyzw
  64: mul r0.y, r0.y, cb2[1].w
  65: mad r0.x, cb2[0].w, r0.x, r0.y
  66: mad r0.x, cb2[2].w, v0.z, r0.x
  67: mad r0.x, cb2[3].w, v0.w, r0.x
  68: mul r0.yz, cb1[6].yyyy, cb3[1].xxyx
  69: mad r0.yz, cb3[0].xxyx, cb1[6].xxxx, r0.yyzy
  70: mul r0.yz, r0.yyzy, cb0[33].yyzy
  71: div r0.xy, r0.xxxx, r0.yzyy
  72: dp2 r0.x, r0.xyxx, r0.xyxx
  73: rsq r0.x, r0.x
  74: mul r0.y, |v4.y|, cb0[33].x
  75: mul r0.x, r0.x, r0.y
  76: mul r0.y, r0.x, l(1.500000)
  77: add r0.z, -cb0[33].w, l(1.000000)
  78: mul r0.y, r0.z, r0.y
  79: mad r0.x, r0.x, l(1.500000), -r0.y
  80: dp3 r0.z, r2.xyzx, r2.xyzx
  81: rsq r0.z, r0.z
  82: mul r3.xyz, r0.zzzz, r2.xyzx
  83: dp3 r0.z, r1.yzxy, r3.xyzx
  84: mad o7.y, |r0.z|, r0.x, r0.y
  85: ge r0.x, l(0.000000), v4.y
  86: and r0.x, r0.x, l(0x3f800000)
  87: add r0.y, -cb0[28].y, cb0[28].z
  88: mad r0.x, r0.x, r0.y, cb0[28].y
  89: div r0.x, r0.x, cb0[33].x
  90: mul r0.y, cb0[10].x, cb0[28].w
  91: mad o7.x, r0.y, l(0.500000), r0.x
  92: mul r0.xyz, r2.yyyy, cb0[18].xyzx
  93: mad r0.xyz, cb0[17].xyzx, r2.xxxx, r0.xyzx
  94: mad o8.xyz, cb0[19].xyzx, r2.zzzz, r0.xyzx
  95: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
// Stats: 140 math, 10 textures, 2 branches
Keywords { "SPOT" }
"#version 120

#ifdef VERTEX
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _ScreenParams;

uniform mat4 _Object2World;
uniform mat4 _World2Object;
uniform vec4 unity_WorldTransformParams;

uniform float _FaceDilate;
uniform mat4 _EnvMatrix;
uniform float _WeightNormal;
uniform float _WeightBold;
uniform float _ScaleRatioA;
uniform float _VertexOffsetX;
uniform float _VertexOffsetY;
uniform float _GradientScale;
uniform float _ScaleX;
uniform float _ScaleY;
uniform float _PerspectiveFilter;
uniform vec4 _MainTex_ST;
uniform vec4 _FaceTex_ST;
attribute vec4 TANGENT;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec4 tmpvar_1;
  vec4 tmpvar_2;
  vec3 tmpvar_3;
  tmpvar_2.zw = gl_Vertex.zw;
  vec2 tmpvar_4;
  float scale_5;
  vec2 pixelSize_6;
  tmpvar_2.x = (gl_Vertex.x + _VertexOffsetX);
  tmpvar_2.y = (gl_Vertex.y + _VertexOffsetY);
  vec4 tmpvar_7;
  tmpvar_7.w = 1.0;
  tmpvar_7.xyz = _WorldSpaceCameraPos;
  tmpvar_3 = (gl_Normal * sign(dot (gl_Normal, 
    ((_World2Object * tmpvar_7).xyz - tmpvar_2.xyz)
  )));
  vec2 tmpvar_8;
  tmpvar_8.x = _ScaleX;
  tmpvar_8.y = _ScaleY;
  mat2 tmpvar_9;
  tmpvar_9[0] = gl_ProjectionMatrix[0].xy;
  tmpvar_9[1] = gl_ProjectionMatrix[1].xy;
  pixelSize_6 = ((gl_ModelViewProjectionMatrix * tmpvar_2).ww / (tmpvar_8 * (tmpvar_9 * _ScreenParams.xy)));
  scale_5 = (inversesqrt(dot (pixelSize_6, pixelSize_6)) * ((
    abs(gl_MultiTexCoord1.y)
   * _GradientScale) * 1.5));
  vec4 v_10;
  float tmpvar_11;
  tmpvar_11 = _World2Object[0].x;
  v_10.x = tmpvar_11;
  float tmpvar_12;
  tmpvar_12 = _World2Object[1].x;
  v_10.y = tmpvar_12;
  float tmpvar_13;
  tmpvar_13 = _World2Object[2].x;
  v_10.z = tmpvar_13;
  float tmpvar_14;
  tmpvar_14 = _World2Object[3].x;
  v_10.w = tmpvar_14;
  vec4 v_15;
  float tmpvar_16;
  tmpvar_16 = _World2Object[0].y;
  v_15.x = tmpvar_16;
  float tmpvar_17;
  tmpvar_17 = _World2Object[1].y;
  v_15.y = tmpvar_17;
  float tmpvar_18;
  tmpvar_18 = _World2Object[2].y;
  v_15.z = tmpvar_18;
  float tmpvar_19;
  tmpvar_19 = _World2Object[3].y;
  v_15.w = tmpvar_19;
  vec4 v_20;
  float tmpvar_21;
  tmpvar_21 = _World2Object[0].z;
  v_20.x = tmpvar_21;
  float tmpvar_22;
  tmpvar_22 = _World2Object[1].z;
  v_20.y = tmpvar_22;
  float tmpvar_23;
  tmpvar_23 = _World2Object[2].z;
  v_20.z = tmpvar_23;
  float tmpvar_24;
  tmpvar_24 = _World2Object[3].z;
  v_20.w = tmpvar_24;
  float tmpvar_25;
  tmpvar_25 = mix ((scale_5 * (1.0 - _PerspectiveFilter)), scale_5, abs(dot (
    normalize((((v_10.xyz * tmpvar_3.x) + (v_15.xyz * tmpvar_3.y)) + (v_20.xyz * tmpvar_3.z)))
  , 
    normalize((_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz))
  )));
  scale_5 = tmpvar_25;
  tmpvar_4.y = tmpvar_25;
  tmpvar_4.x = ((mix (_WeightNormal, _WeightBold, 
    float((0.0 >= gl_MultiTexCoord1.y))
  ) / _GradientScale) + ((_FaceDilate * _ScaleRatioA) * 0.5));
  vec2 tmpvar_26;
  tmpvar_26.x = ((floor(gl_MultiTexCoord1.x) * 5.0) / 4096.0);
  tmpvar_26.y = (fract(gl_MultiTexCoord1.x) * 5.0);
  mat3 tmpvar_27;
  tmpvar_27[0] = _EnvMatrix[0].xyz;
  tmpvar_27[1] = _EnvMatrix[1].xyz;
  tmpvar_27[2] = _EnvMatrix[2].xyz;
  tmpvar_1.xy = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  tmpvar_1.zw = ((tmpvar_26 * _FaceTex_ST.xy) + _FaceTex_ST.zw);
  vec4 v_28;
  v_28.x = tmpvar_11;
  v_28.y = tmpvar_12;
  v_28.z = tmpvar_13;
  v_28.w = tmpvar_14;
  vec4 v_29;
  v_29.x = tmpvar_16;
  v_29.y = tmpvar_17;
  v_29.z = tmpvar_18;
  v_29.w = tmpvar_19;
  vec4 v_30;
  v_30.x = tmpvar_21;
  v_30.y = tmpvar_22;
  v_30.z = tmpvar_23;
  v_30.w = tmpvar_24;
  vec3 tmpvar_31;
  tmpvar_31 = normalize(((
    (v_28.xyz * tmpvar_3.x)
   + 
    (v_29.xyz * tmpvar_3.y)
  ) + (v_30.xyz * tmpvar_3.z)));
  mat3 tmpvar_32;
  tmpvar_32[0] = _Object2World[0].xyz;
  tmpvar_32[1] = _Object2World[1].xyz;
  tmpvar_32[2] = _Object2World[2].xyz;
  vec3 tmpvar_33;
  tmpvar_33 = normalize((tmpvar_32 * TANGENT.xyz));
  vec3 tmpvar_34;
  tmpvar_34 = (((tmpvar_31.yzx * tmpvar_33.zxy) - (tmpvar_31.zxy * tmpvar_33.yzx)) * (TANGENT.w * unity_WorldTransformParams.w));
  vec3 tmpvar_35;
  tmpvar_35.x = tmpvar_33.x;
  tmpvar_35.y = tmpvar_34.x;
  tmpvar_35.z = tmpvar_31.x;
  vec3 tmpvar_36;
  tmpvar_36.x = tmpvar_33.y;
  tmpvar_36.y = tmpvar_34.y;
  tmpvar_36.z = tmpvar_31.y;
  vec3 tmpvar_37;
  tmpvar_37.x = tmpvar_33.z;
  tmpvar_37.y = tmpvar_34.z;
  tmpvar_37.z = tmpvar_31.z;
  gl_Position = (gl_ModelViewProjectionMatrix * tmpvar_2);
  xlv_TEXCOORD0 = tmpvar_1;
  xlv_TEXCOORD1 = tmpvar_35;
  xlv_TEXCOORD2 = tmpvar_36;
  xlv_TEXCOORD3 = tmpvar_37;
  xlv_TEXCOORD4 = (_Object2World * tmpvar_2).xyz;
  xlv_COLOR0 = gl_Color;
  xlv_TEXCOORD5 = tmpvar_4;
  xlv_TEXCOORD6 = (tmpvar_27 * (_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz));
}


#endif
#ifdef FRAGMENT
uniform vec4 _Time;
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _WorldSpaceLightPos0;
uniform vec4 _LightColor0;
uniform vec4 _SpecColor;
uniform sampler2D _LightTexture0;
uniform mat4 _LightMatrix0;
uniform sampler2D _LightTextureB0;
uniform sampler2D _FaceTex;
uniform float _FaceUVSpeedX;
uniform float _FaceUVSpeedY;
uniform vec4 _FaceColor;
uniform float _OutlineSoftness;
uniform sampler2D _OutlineTex;
uniform float _OutlineUVSpeedX;
uniform float _OutlineUVSpeedY;
uniform vec4 _OutlineColor;
uniform float _OutlineWidth;
uniform float _Bevel;
uniform float _BevelOffset;
uniform float _BevelWidth;
uniform float _BevelClamp;
uniform float _BevelRoundness;
uniform sampler2D _BumpMap;
uniform float _BumpOutline;
uniform float _BumpFace;
uniform float _ShaderFlags;
uniform float _ScaleRatioA;
uniform sampler2D _MainTex;
uniform float _TextureWidth;
uniform float _TextureHeight;
uniform float _GradientScale;
uniform float _FaceShininess;
uniform float _OutlineShininess;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
void main ()
{
  vec3 tmpvar_1;
  vec3 worldN_2;
  vec3 tmpvar_3;
  vec3 tmpvar_4;
  float tmpvar_5;
  float tmpvar_6;
  vec3 tmpvar_7;
  tmpvar_7 = normalize((_WorldSpaceLightPos0.xyz - xlv_TEXCOORD4));
  vec3 tmpvar_8;
  tmpvar_8 = normalize((_WorldSpaceCameraPos - xlv_TEXCOORD4));
  tmpvar_3 = vec3(0.0, 0.0, 0.0);
  tmpvar_6 = 0.0;
  tmpvar_5 = 0.0;
  vec3 tmpvar_9;
  vec3 tmpvar_10;
  float tmpvar_11;
  float tmpvar_12;
  tmpvar_9 = tmpvar_3;
  tmpvar_10 = tmpvar_4;
  tmpvar_11 = tmpvar_5;
  tmpvar_12 = tmpvar_6;
  vec3 bump_13;
  vec4 outlineColor_14;
  vec4 faceColor_15;
  vec3 tmpvar_16;
  tmpvar_16.z = 0.0;
  tmpvar_16.x = (1.0/(_TextureWidth));
  tmpvar_16.y = (1.0/(_TextureHeight));
  vec4 tmpvar_17;
  tmpvar_17.x = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.xz)).w;
  tmpvar_17.y = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.xz)).w;
  tmpvar_17.z = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.zy)).w;
  tmpvar_17.w = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.zy)).w;
  float tmpvar_18;
  tmpvar_18 = (((
    (0.5 - texture2D (_MainTex, xlv_TEXCOORD0.xy).w)
   - xlv_TEXCOORD5.x) * xlv_TEXCOORD5.y) + 0.5);
  float tmpvar_19;
  tmpvar_19 = ((_OutlineWidth * _ScaleRatioA) * xlv_TEXCOORD5.y);
  float tmpvar_20;
  tmpvar_20 = ((_OutlineSoftness * _ScaleRatioA) * xlv_TEXCOORD5.y);
  outlineColor_14.xyz = _OutlineColor.xyz;
  faceColor_15 = (_FaceColor * xlv_COLOR0);
  outlineColor_14.w = (_OutlineColor.w * xlv_COLOR0.w);
  vec2 tmpvar_21;
  tmpvar_21.x = (xlv_TEXCOORD0.z + (_FaceUVSpeedX * _Time.y));
  tmpvar_21.y = (xlv_TEXCOORD0.w + (_FaceUVSpeedY * _Time.y));
  faceColor_15 = (faceColor_15 * texture2D (_FaceTex, tmpvar_21));
  vec2 tmpvar_22;
  tmpvar_22.x = (xlv_TEXCOORD0.z + (_OutlineUVSpeedX * _Time.y));
  tmpvar_22.y = (xlv_TEXCOORD0.w + (_OutlineUVSpeedY * _Time.y));
  outlineColor_14 = (outlineColor_14 * texture2D (_OutlineTex, tmpvar_22));
  vec4 faceColor_23;
  faceColor_23.w = faceColor_15.w;
  vec4 outlineColor_24;
  outlineColor_24.w = outlineColor_14.w;
  faceColor_23.xyz = (faceColor_15.xyz * faceColor_15.w);
  outlineColor_24.xyz = (outlineColor_14.xyz * outlineColor_14.w);
  faceColor_23 = (mix (faceColor_23, outlineColor_24, vec4((
    clamp ((tmpvar_18 + (tmpvar_19 * 0.5)), 0.0, 1.0)
   * 
    sqrt(min (1.0, tmpvar_19))
  ))) * (1.0 - clamp (
    (((tmpvar_18 - (tmpvar_19 * 0.5)) + (tmpvar_20 * 0.5)) / (1.0 + tmpvar_20))
  , 0.0, 1.0)));
  faceColor_15.w = faceColor_23.w;
  faceColor_15.xyz = (faceColor_23.xyz / max (faceColor_23.w, 0.0001));
  vec4 h_25;
  h_25 = tmpvar_17;
  float tmpvar_26;
  tmpvar_26 = (_ShaderFlags / 2.0);
  float tmpvar_27;
  tmpvar_27 = (fract(abs(tmpvar_26)) * 2.0);
  float tmpvar_28;
  if ((tmpvar_26 >= 0.0)) {
    tmpvar_28 = tmpvar_27;
  } else {
    tmpvar_28 = -(tmpvar_27);
  };
  h_25 = (tmpvar_17 + (xlv_TEXCOORD5.x + _BevelOffset));
  float tmpvar_29;
  tmpvar_29 = max (0.01, (_OutlineWidth + _BevelWidth));
  h_25 = (h_25 - 0.5);
  h_25 = (h_25 / tmpvar_29);
  vec4 tmpvar_30;
  tmpvar_30 = clamp ((h_25 + 0.5), 0.0, 1.0);
  h_25 = tmpvar_30;
  if (bool(float((tmpvar_28 >= 1.0)))) {
    h_25 = (1.0 - abs((
      (tmpvar_30 * 2.0)
     - 1.0)));
  };
  h_25 = (min (mix (h_25, 
    sin(((h_25 * 3.141592) / 2.0))
  , vec4(_BevelRoundness)), vec4((1.0 - _BevelClamp))) * ((_Bevel * tmpvar_29) * (_GradientScale * -2.0)));
  vec3 tmpvar_31;
  tmpvar_31.xy = vec2(1.0, 0.0);
  tmpvar_31.z = (h_25.y - h_25.x);
  vec3 tmpvar_32;
  tmpvar_32 = normalize(tmpvar_31);
  vec3 tmpvar_33;
  tmpvar_33.xy = vec2(0.0, -1.0);
  tmpvar_33.z = (h_25.w - h_25.z);
  vec3 tmpvar_34;
  tmpvar_34 = normalize(tmpvar_33);
  vec3 normal_35;
  normal_35.xy = ((texture2D (_BumpMap, xlv_TEXCOORD0.zw).wy * 2.0) - 1.0);
  normal_35.z = sqrt((1.0 - clamp (
    dot (normal_35.xy, normal_35.xy)
  , 0.0, 1.0)));
  bump_13 = (normal_35 * mix (_BumpFace, _BumpOutline, clamp (
    (tmpvar_18 + (tmpvar_19 * 0.5))
  , 0.0, 1.0)));
  vec3 tmpvar_36;
  tmpvar_36 = mix (vec3(0.0, 0.0, 1.0), bump_13, faceColor_23.www);
  bump_13 = tmpvar_36;
  tmpvar_9 = faceColor_15.xyz;
  tmpvar_10 = -(normalize((
    ((tmpvar_32.yzx * tmpvar_34.zxy) - (tmpvar_32.zxy * tmpvar_34.yzx))
   - tmpvar_36)));
  tmpvar_11 = 1.0;
  tmpvar_12 = faceColor_15.w;
  tmpvar_3 = tmpvar_9;
  tmpvar_5 = tmpvar_11;
  tmpvar_6 = tmpvar_12;
  vec4 tmpvar_37;
  tmpvar_37.w = 1.0;
  tmpvar_37.xyz = xlv_TEXCOORD4;
  vec4 tmpvar_38;
  tmpvar_38 = (_LightMatrix0 * tmpvar_37);
  worldN_2.x = dot (xlv_TEXCOORD1, tmpvar_10);
  worldN_2.y = dot (xlv_TEXCOORD2, tmpvar_10);
  worldN_2.z = dot (xlv_TEXCOORD3, tmpvar_10);
  tmpvar_4 = worldN_2;
  tmpvar_1 = (_LightColor0.xyz * ((
    float((tmpvar_38.z > 0.0))
   * texture2D (_LightTexture0, 
    ((tmpvar_38.xy / tmpvar_38.w) + 0.5)
  ).w) * texture2D (_LightTextureB0, vec2(dot (tmpvar_38.xyz, tmpvar_38.xyz))).w));
  vec4 c_39;
  vec4 c_40;
  c_40.xyz = (((faceColor_15.xyz * tmpvar_1) * max (0.0, 
    dot (worldN_2, tmpvar_7)
  )) + ((tmpvar_1 * _SpecColor.xyz) * pow (
    max (0.0, dot (worldN_2, normalize((tmpvar_7 + tmpvar_8))))
  , 
    (mix (_FaceShininess, _OutlineShininess, clamp ((tmpvar_18 + 
      (tmpvar_19 * 0.5)
    ), 0.0, 1.0)) * 128.0)
  )));
  c_40.w = tmpvar_12;
  c_39.w = c_40.w;
  c_39.xyz = c_40.xyz;
  gl_FragData[0] = c_39;
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 95 math
Keywords { "SPOT" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
Matrix 10 [_EnvMatrix] 3
Matrix 4 [_Object2World] 3
Matrix 7 [_World2Object] 3
Matrix 0 [glstate_matrix_mvp]
Matrix 13 [glstate_matrix_projection] 2
Float 18 [_FaceDilate]
Vector 29 [_FaceTex_ST]
Float 24 [_GradientScale]
Vector 28 [_MainTex_ST]
Float 27 [_PerspectiveFilter]
Float 21 [_ScaleRatioA]
Float 25 [_ScaleX]
Float 26 [_ScaleY]
Vector 16 [_ScreenParams]
Float 22 [_VertexOffsetX]
Float 23 [_VertexOffsetY]
Float 20 [_WeightBold]
Float 19 [_WeightNormal]
Vector 15 [_WorldSpaceCameraPos]
Vector 17 [unity_WorldTransformParams]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   row_major float4x4 _EnvMatrix;
//   float _FaceDilate;
//   float4 _FaceTex_ST;
//   float _GradientScale;
//   float4 _MainTex_ST;
//   row_major float4x4 _Object2World;
//   float _PerspectiveFilter;
//   float _ScaleRatioA;
//   float _ScaleX;
//   float _ScaleY;
//   float4 _ScreenParams;
//   float _VertexOffsetX;
//   float _VertexOffsetY;
//   float _WeightBold;
//   float _WeightNormal;
//   row_major float4x4 _World2Object;
//   float3 _WorldSpaceCameraPos;
//   row_major float4x4 glstate_matrix_mvp;
//   row_major float4x4 glstate_matrix_projection;
//   float4 unity_WorldTransformParams;
//
//
// Registers:
//
//   Name                       Reg   Size
//   -------------------------- ----- ----
//   glstate_matrix_mvp         c0       4
//   _Object2World              c4       3
//   _World2Object              c7       3
//   _EnvMatrix                 c10      3
//   glstate_matrix_projection  c13      2
//   _WorldSpaceCameraPos       c15      1
//   _ScreenParams              c16      1
//   unity_WorldTransformParams c17      1
//   _FaceDilate                c18      1
//   _WeightNormal              c19      1
//   _WeightBold                c20      1
//   _ScaleRatioA               c21      1
//   _VertexOffsetX             c22      1
//   _VertexOffsetY             c23      1
//   _GradientScale             c24      1
//   _ScaleX                    c25      1
//   _ScaleY                    c26      1
//   _PerspectiveFilter         c27      1
//   _MainTex_ST                c28      1
//   _FaceTex_ST                c29      1
//

    vs_3_0
    def c30, 0, 1, 1.5, 0.5
    def c31, 0.00122070313, 5, 0, 0
    dcl_position v0
    dcl_tangent v1
    dcl_normal v2
    dcl_texcoord v3
    dcl_texcoord1 v4
    dcl_color v5
    dcl_position o0
    dcl_texcoord o1
    dcl_texcoord1 o2.xyz
    dcl_texcoord2 o3.xyz
    dcl_texcoord3 o4.xyz
    dcl_texcoord4 o5.xyz
    dcl_color o6
    dcl_texcoord5 o7.xy
    dcl_texcoord6 o8.xyz
    mov r0.xy, c30
    mad r1, c15.xyzx, r0.yyyx, r0.xxxy
    dp4 r2.x, c7, r1
    dp4 r2.y, c8, r1
    dp4 r2.z, c9, r1
    add r1.x, c22.x, v0.x
    add r1.y, c23.x, v0.y
    mov r1.zw, v0
    add r0.xzw, -r1.xyyz, r2.xyyz
    dp3 r0.x, v2, r0.xzww
    slt r0.z, -r0.x, r0.x
    slt r0.x, r0.x, -r0.x
    add r0.x, -r0.x, r0.z
    mul r0.xzw, r0.x, v2.xyyz
    mul r2.xyz, r0.z, c8.zxyw
    mad r2.xyz, c7.zxyw, r0.x, r2
    mad r0.xzw, c9.zyxy, r0.w, r2.xyyz
    dp3 r2.x, r0.xzww, r0.xzww
    rsq r2.x, r2.x
    mul r0.xzw, r0, r2.x
    dp4 r2.x, c4, r1
    dp4 r2.y, c5, r1
    dp4 r2.z, c6, r1
    add r3.xyz, -r2, c15
    mov o5.xyz, r2
    nrm r2.xyz, r3
    dp3 r2.x, r0.zwxw, r2
    mov r4.xy, c16
    mul r2.yz, r4.xxyw, c13.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c25.x
    rcp r5.x, r2.y
    mul r2.yz, r4.xxyw, c14.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c26.x
    rcp r5.y, r2.y
    dp4 r2.y, c3, r1
    mul r2.zw, r5.xyxy, r2.y
    mov o0.w, r2.y
    mul r2.yz, r2.xzww, r2.xzww
    add r2.y, r2.z, r2.y
    rsq r2.y, r2.y
    mul r2.z, c24.x, v4_abs.y
    mul r2.y, r2.y, r2.z
    mul r2.z, r2.y, c30.z
    add r0.y, r0.y, -c27.x
    mul r0.y, r0.y, r2.z
    mad r2.y, r2.y, c30.z, -r0.y
    mad o7.y, r2_abs.x, r2.y, r0.y
    sge r0.y, c30.x, v4.y
    mov r2.x, c19.x
    add r2.x, -r2.x, c20.x
    mad r0.y, r0.y, r2.x, c19.x
    mov r2.x, c18.x
    mul r2.x, r2.x, c21.x
    mul r2.x, r2.x, c30.w
    rcp r2.y, c24.x
    mad o7.x, r0.y, r2.y, r2.x
    dp3 o8.x, c10, r3
    dp3 o8.y, c11, r3
    dp3 o8.z, c12, r3
    dp4 o0.x, c0, r1
    dp4 o0.y, c1, r1
    dp4 o0.z, c2, r1
    mad o1.xy, v3, c28, c28.zwzw
    frc r0.y, v4.x
    add r1.x, -r0.y, v4.x
    mul r1.w, r0.y, c29.y
    mul r1.z, r1.x, c29.x
    mov r2.zw, c29
    mad o1.zw, r1, c31.xyxy, r2
    dp3 r1.z, c4, v1
    dp3 r1.x, c5, v1
    dp3 r1.y, c6, v1
    dp3 r0.y, r1, r1
    rsq r0.y, r0.y
    mul r1.xyz, r0.y, r1
    mov o2.x, r1.z
    mul r2.xyz, r0.xzww, r1
    mad r2.xyz, r0.wxzw, r1.yzxw, -r2
    mul r0.y, c17.w, v1.w
    mul r2.xyz, r0.y, r2
    mov o2.y, r2.x
    mov o2.z, r0.z
    mov o3.x, r1.x
    mov o4.x, r1.y
    mov o3.y, r2.y
    mov o4.y, r2.z
    mov o3.z, r0.w
    mov o4.z, r0.x
    mov o6, v5

// approximately 93 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 73 math
Keywords { "SPOT" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
ConstBuffer "$Globals" 656
Matrix 336 [_EnvMatrix]
Float 224 [_FaceDilate]
Float 516 [_WeightNormal]
Float 520 [_WeightBold]
Float 524 [_ScaleRatioA]
Float 536 [_VertexOffsetX]
Float 540 [_VertexOffsetY]
Float 592 [_GradientScale]
Float 596 [_ScaleX]
Float 600 [_ScaleY]
Float 604 [_PerspectiveFilter]
Vector 624 [_MainTex_ST]
Vector 640 [_FaceTex_ST]
ConstBuffer "UnityPerCamera" 144
Vector 64 [_WorldSpaceCameraPos] 3
Vector 96 [_ScreenParams]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
Matrix 256 [_World2Object]
Vector 336 [unity_WorldTransformParams]
ConstBuffer "UnityPerFrame" 256
Matrix 0 [glstate_matrix_projection]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityPerDraw" 2
BindCB  "UnityPerFrame" 3
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// TANGENT                  0   xyzw        1     NONE   float   xyzw
// NORMAL                   0   xyz         2     NONE   float   xyz 
// TEXCOORD                 0   xyzw        3     NONE   float   xy  
// TEXCOORD                 1   xyzw        4     NONE   float   xy  
// TEXCOORD                 2   xyzw        5     NONE   float       
// TEXCOORD                 3   xyzw        6     NONE   float       
// COLOR                    0   xyzw        7     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float   xyz 
//
      vs_4_0
      dcl_constantbuffer cb0[41], immediateIndexed
      dcl_constantbuffer cb1[7], immediateIndexed
      dcl_constantbuffer cb2[22], immediateIndexed
      dcl_constantbuffer cb3[2], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v1.xyzw
      dcl_input v2.xyz
      dcl_input v3.xy
      dcl_input v4.xy
      dcl_input v7.xyzw
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xyzw
      dcl_output o2.xyz
      dcl_output o3.xyz
      dcl_output o4.xyz
      dcl_output o5.xyz
      dcl_output o6.xyzw
      dcl_output o7.xy
      dcl_output o8.xyz
      dcl_temps 4
   0: add r0.xy, v0.xyxx, cb0[33].zwzz
   1: mul r1.xyzw, r0.yyyy, cb2[1].xyzw
   2: mad r1.xyzw, cb2[0].xyzw, r0.xxxx, r1.xyzw
   3: mad r1.xyzw, cb2[2].xyzw, v0.zzzz, r1.xyzw
   4: mad o0.xyzw, cb2[3].xyzw, v0.wwww, r1.xyzw
   5: round_ni r0.w, v4.x
   6: mul r1.z, r0.w, cb0[40].x
   7: frc r0.w, v4.x
   8: mul r1.w, r0.w, cb0[40].y
   9: mad o1.zw, r1.zzzw, l(0.000000, 0.000000, 0.001221, 5.000000), cb0[40].zzzw
  10: mad o1.xy, v3.xyxx, cb0[39].xyxx, cb0[39].zwzz
  11: mul r1.xyz, cb1[4].yyyy, cb2[17].xyzx
  12: mad r1.xyz, cb2[16].xyzx, cb1[4].xxxx, r1.xyzx
  13: mad r1.xyz, cb2[18].xyzx, cb1[4].zzzz, r1.xyzx
  14: add r1.xyz, r1.xyzx, cb2[19].xyzx
  15: mov r0.z, v0.z
  16: add r1.xyz, -r0.xyzx, r1.xyzx
  17: dp3 r0.z, v2.xyzx, r1.xyzx
  18: lt r0.w, l(0.000000), r0.z
  19: lt r0.z, r0.z, l(0.000000)
  20: iadd r0.z, -r0.w, r0.z
  21: itof r0.z, r0.z
  22: mul r1.xyz, r0.zzzz, v2.xyzx
  23: mov r2.y, cb2[16].y
  24: mov r2.z, cb2[17].y
  25: mov r2.x, cb2[18].y
  26: mul r2.xyz, r1.yyyy, r2.xyzx
  27: mov r3.y, cb2[16].x
  28: mov r3.z, cb2[17].x
  29: mov r3.x, cb2[18].x
  30: mad r1.xyw, r3.xyxz, r1.xxxx, r2.xyxz
  31: mov r2.y, cb2[16].z
  32: mov r2.z, cb2[17].z
  33: mov r2.x, cb2[18].z
  34: mad r1.xyz, r2.xyzx, r1.zzzz, r1.xywx
  35: dp3 r0.z, r1.xyzx, r1.xyzx
  36: rsq r0.z, r0.z
  37: mul r1.xyz, r0.zzzz, r1.xyzx
  38: mov o2.z, r1.y
  39: mul r2.xyz, v1.yyyy, cb2[13].yzxy
  40: mad r2.xyz, cb2[12].yzxy, v1.xxxx, r2.xyzx
  41: mad r2.xyz, cb2[14].yzxy, v1.zzzz, r2.xyzx
  42: dp3 r0.z, r2.xyzx, r2.xyzx
  43: rsq r0.z, r0.z
  44: mul r2.xyz, r0.zzzz, r2.xyzx
  45: mul r3.xyz, r1.xyzx, r2.xyzx
  46: mad r3.xyz, r1.zxyz, r2.yzxy, -r3.xyzx
  47: mul r0.z, v1.w, cb2[21].w
  48: mul r3.xyz, r0.zzzz, r3.xyzx
  49: mov o2.y, r3.x
  50: mov o2.x, r2.z
  51: mov o3.x, r2.x
  52: mov o4.x, r2.y
  53: mov o3.z, r1.z
  54: mov o3.y, r3.y
  55: mov o4.y, r3.z
  56: mov o4.z, r1.x
  57: mul r2.xyz, r0.yyyy, cb2[13].xyzx
  58: mad r2.xyz, cb2[12].xyzx, r0.xxxx, r2.xyzx
  59: mad r2.xyz, cb2[14].xyzx, v0.zzzz, r2.xyzx
  60: mad r2.xyz, cb2[15].xyzx, v0.wwww, r2.xyzx
  61: mov o5.xyz, r2.xyzx
  62: add r2.xyz, -r2.xyzx, cb1[4].xyzx
  63: mov o6.xyzw, v7.xyzw
  64: mul r0.y, r0.y, cb2[1].w
  65: mad r0.x, cb2[0].w, r0.x, r0.y
  66: mad r0.x, cb2[2].w, v0.z, r0.x
  67: mad r0.x, cb2[3].w, v0.w, r0.x
  68: mul r0.yz, cb1[6].yyyy, cb3[1].xxyx
  69: mad r0.yz, cb3[0].xxyx, cb1[6].xxxx, r0.yyzy
  70: mul r0.yz, r0.yyzy, cb0[37].yyzy
  71: div r0.xy, r0.xxxx, r0.yzyy
  72: dp2 r0.x, r0.xyxx, r0.xyxx
  73: rsq r0.x, r0.x
  74: mul r0.y, |v4.y|, cb0[37].x
  75: mul r0.x, r0.x, r0.y
  76: mul r0.y, r0.x, l(1.500000)
  77: add r0.z, -cb0[37].w, l(1.000000)
  78: mul r0.y, r0.z, r0.y
  79: mad r0.x, r0.x, l(1.500000), -r0.y
  80: dp3 r0.z, r2.xyzx, r2.xyzx
  81: rsq r0.z, r0.z
  82: mul r3.xyz, r0.zzzz, r2.xyzx
  83: dp3 r0.z, r1.yzxy, r3.xyzx
  84: mad o7.y, |r0.z|, r0.x, r0.y
  85: ge r0.x, l(0.000000), v4.y
  86: and r0.x, r0.x, l(0x3f800000)
  87: add r0.y, -cb0[32].y, cb0[32].z
  88: mad r0.x, r0.x, r0.y, cb0[32].y
  89: div r0.x, r0.x, cb0[37].x
  90: mul r0.y, cb0[14].x, cb0[32].w
  91: mad o7.x, r0.y, l(0.500000), r0.x
  92: mul r0.xyz, r2.yyyy, cb0[22].xyzx
  93: mad r0.xyz, cb0[21].xyzx, r2.xxxx, r0.xyzx
  94: mad o8.xyz, cb0[23].xyzx, r2.zzzz, r0.xyzx
  95: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
// Stats: 135 math, 10 textures, 2 branches
Keywords { "POINT_COOKIE" }
"#version 120

#ifdef VERTEX
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _ScreenParams;

uniform mat4 _Object2World;
uniform mat4 _World2Object;
uniform vec4 unity_WorldTransformParams;

uniform float _FaceDilate;
uniform mat4 _EnvMatrix;
uniform float _WeightNormal;
uniform float _WeightBold;
uniform float _ScaleRatioA;
uniform float _VertexOffsetX;
uniform float _VertexOffsetY;
uniform float _GradientScale;
uniform float _ScaleX;
uniform float _ScaleY;
uniform float _PerspectiveFilter;
uniform vec4 _MainTex_ST;
uniform vec4 _FaceTex_ST;
attribute vec4 TANGENT;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec4 tmpvar_1;
  vec4 tmpvar_2;
  vec3 tmpvar_3;
  tmpvar_2.zw = gl_Vertex.zw;
  vec2 tmpvar_4;
  float scale_5;
  vec2 pixelSize_6;
  tmpvar_2.x = (gl_Vertex.x + _VertexOffsetX);
  tmpvar_2.y = (gl_Vertex.y + _VertexOffsetY);
  vec4 tmpvar_7;
  tmpvar_7.w = 1.0;
  tmpvar_7.xyz = _WorldSpaceCameraPos;
  tmpvar_3 = (gl_Normal * sign(dot (gl_Normal, 
    ((_World2Object * tmpvar_7).xyz - tmpvar_2.xyz)
  )));
  vec2 tmpvar_8;
  tmpvar_8.x = _ScaleX;
  tmpvar_8.y = _ScaleY;
  mat2 tmpvar_9;
  tmpvar_9[0] = gl_ProjectionMatrix[0].xy;
  tmpvar_9[1] = gl_ProjectionMatrix[1].xy;
  pixelSize_6 = ((gl_ModelViewProjectionMatrix * tmpvar_2).ww / (tmpvar_8 * (tmpvar_9 * _ScreenParams.xy)));
  scale_5 = (inversesqrt(dot (pixelSize_6, pixelSize_6)) * ((
    abs(gl_MultiTexCoord1.y)
   * _GradientScale) * 1.5));
  vec4 v_10;
  float tmpvar_11;
  tmpvar_11 = _World2Object[0].x;
  v_10.x = tmpvar_11;
  float tmpvar_12;
  tmpvar_12 = _World2Object[1].x;
  v_10.y = tmpvar_12;
  float tmpvar_13;
  tmpvar_13 = _World2Object[2].x;
  v_10.z = tmpvar_13;
  float tmpvar_14;
  tmpvar_14 = _World2Object[3].x;
  v_10.w = tmpvar_14;
  vec4 v_15;
  float tmpvar_16;
  tmpvar_16 = _World2Object[0].y;
  v_15.x = tmpvar_16;
  float tmpvar_17;
  tmpvar_17 = _World2Object[1].y;
  v_15.y = tmpvar_17;
  float tmpvar_18;
  tmpvar_18 = _World2Object[2].y;
  v_15.z = tmpvar_18;
  float tmpvar_19;
  tmpvar_19 = _World2Object[3].y;
  v_15.w = tmpvar_19;
  vec4 v_20;
  float tmpvar_21;
  tmpvar_21 = _World2Object[0].z;
  v_20.x = tmpvar_21;
  float tmpvar_22;
  tmpvar_22 = _World2Object[1].z;
  v_20.y = tmpvar_22;
  float tmpvar_23;
  tmpvar_23 = _World2Object[2].z;
  v_20.z = tmpvar_23;
  float tmpvar_24;
  tmpvar_24 = _World2Object[3].z;
  v_20.w = tmpvar_24;
  float tmpvar_25;
  tmpvar_25 = mix ((scale_5 * (1.0 - _PerspectiveFilter)), scale_5, abs(dot (
    normalize((((v_10.xyz * tmpvar_3.x) + (v_15.xyz * tmpvar_3.y)) + (v_20.xyz * tmpvar_3.z)))
  , 
    normalize((_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz))
  )));
  scale_5 = tmpvar_25;
  tmpvar_4.y = tmpvar_25;
  tmpvar_4.x = ((mix (_WeightNormal, _WeightBold, 
    float((0.0 >= gl_MultiTexCoord1.y))
  ) / _GradientScale) + ((_FaceDilate * _ScaleRatioA) * 0.5));
  vec2 tmpvar_26;
  tmpvar_26.x = ((floor(gl_MultiTexCoord1.x) * 5.0) / 4096.0);
  tmpvar_26.y = (fract(gl_MultiTexCoord1.x) * 5.0);
  mat3 tmpvar_27;
  tmpvar_27[0] = _EnvMatrix[0].xyz;
  tmpvar_27[1] = _EnvMatrix[1].xyz;
  tmpvar_27[2] = _EnvMatrix[2].xyz;
  tmpvar_1.xy = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  tmpvar_1.zw = ((tmpvar_26 * _FaceTex_ST.xy) + _FaceTex_ST.zw);
  vec4 v_28;
  v_28.x = tmpvar_11;
  v_28.y = tmpvar_12;
  v_28.z = tmpvar_13;
  v_28.w = tmpvar_14;
  vec4 v_29;
  v_29.x = tmpvar_16;
  v_29.y = tmpvar_17;
  v_29.z = tmpvar_18;
  v_29.w = tmpvar_19;
  vec4 v_30;
  v_30.x = tmpvar_21;
  v_30.y = tmpvar_22;
  v_30.z = tmpvar_23;
  v_30.w = tmpvar_24;
  vec3 tmpvar_31;
  tmpvar_31 = normalize(((
    (v_28.xyz * tmpvar_3.x)
   + 
    (v_29.xyz * tmpvar_3.y)
  ) + (v_30.xyz * tmpvar_3.z)));
  mat3 tmpvar_32;
  tmpvar_32[0] = _Object2World[0].xyz;
  tmpvar_32[1] = _Object2World[1].xyz;
  tmpvar_32[2] = _Object2World[2].xyz;
  vec3 tmpvar_33;
  tmpvar_33 = normalize((tmpvar_32 * TANGENT.xyz));
  vec3 tmpvar_34;
  tmpvar_34 = (((tmpvar_31.yzx * tmpvar_33.zxy) - (tmpvar_31.zxy * tmpvar_33.yzx)) * (TANGENT.w * unity_WorldTransformParams.w));
  vec3 tmpvar_35;
  tmpvar_35.x = tmpvar_33.x;
  tmpvar_35.y = tmpvar_34.x;
  tmpvar_35.z = tmpvar_31.x;
  vec3 tmpvar_36;
  tmpvar_36.x = tmpvar_33.y;
  tmpvar_36.y = tmpvar_34.y;
  tmpvar_36.z = tmpvar_31.y;
  vec3 tmpvar_37;
  tmpvar_37.x = tmpvar_33.z;
  tmpvar_37.y = tmpvar_34.z;
  tmpvar_37.z = tmpvar_31.z;
  gl_Position = (gl_ModelViewProjectionMatrix * tmpvar_2);
  xlv_TEXCOORD0 = tmpvar_1;
  xlv_TEXCOORD1 = tmpvar_35;
  xlv_TEXCOORD2 = tmpvar_36;
  xlv_TEXCOORD3 = tmpvar_37;
  xlv_TEXCOORD4 = (_Object2World * tmpvar_2).xyz;
  xlv_COLOR0 = gl_Color;
  xlv_TEXCOORD5 = tmpvar_4;
  xlv_TEXCOORD6 = (tmpvar_27 * (_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz));
}


#endif
#ifdef FRAGMENT
uniform vec4 _Time;
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _WorldSpaceLightPos0;
uniform vec4 _LightColor0;
uniform vec4 _SpecColor;
uniform samplerCube _LightTexture0;
uniform mat4 _LightMatrix0;
uniform sampler2D _LightTextureB0;
uniform sampler2D _FaceTex;
uniform float _FaceUVSpeedX;
uniform float _FaceUVSpeedY;
uniform vec4 _FaceColor;
uniform float _OutlineSoftness;
uniform sampler2D _OutlineTex;
uniform float _OutlineUVSpeedX;
uniform float _OutlineUVSpeedY;
uniform vec4 _OutlineColor;
uniform float _OutlineWidth;
uniform float _Bevel;
uniform float _BevelOffset;
uniform float _BevelWidth;
uniform float _BevelClamp;
uniform float _BevelRoundness;
uniform sampler2D _BumpMap;
uniform float _BumpOutline;
uniform float _BumpFace;
uniform float _ShaderFlags;
uniform float _ScaleRatioA;
uniform sampler2D _MainTex;
uniform float _TextureWidth;
uniform float _TextureHeight;
uniform float _GradientScale;
uniform float _FaceShininess;
uniform float _OutlineShininess;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
void main ()
{
  vec3 tmpvar_1;
  vec3 worldN_2;
  vec3 tmpvar_3;
  vec3 tmpvar_4;
  float tmpvar_5;
  float tmpvar_6;
  vec3 tmpvar_7;
  tmpvar_7 = normalize((_WorldSpaceLightPos0.xyz - xlv_TEXCOORD4));
  vec3 tmpvar_8;
  tmpvar_8 = normalize((_WorldSpaceCameraPos - xlv_TEXCOORD4));
  tmpvar_3 = vec3(0.0, 0.0, 0.0);
  tmpvar_6 = 0.0;
  tmpvar_5 = 0.0;
  vec3 tmpvar_9;
  vec3 tmpvar_10;
  float tmpvar_11;
  float tmpvar_12;
  tmpvar_9 = tmpvar_3;
  tmpvar_10 = tmpvar_4;
  tmpvar_11 = tmpvar_5;
  tmpvar_12 = tmpvar_6;
  vec3 bump_13;
  vec4 outlineColor_14;
  vec4 faceColor_15;
  vec3 tmpvar_16;
  tmpvar_16.z = 0.0;
  tmpvar_16.x = (1.0/(_TextureWidth));
  tmpvar_16.y = (1.0/(_TextureHeight));
  vec4 tmpvar_17;
  tmpvar_17.x = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.xz)).w;
  tmpvar_17.y = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.xz)).w;
  tmpvar_17.z = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_16.zy)).w;
  tmpvar_17.w = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_16.zy)).w;
  float tmpvar_18;
  tmpvar_18 = (((
    (0.5 - texture2D (_MainTex, xlv_TEXCOORD0.xy).w)
   - xlv_TEXCOORD5.x) * xlv_TEXCOORD5.y) + 0.5);
  float tmpvar_19;
  tmpvar_19 = ((_OutlineWidth * _ScaleRatioA) * xlv_TEXCOORD5.y);
  float tmpvar_20;
  tmpvar_20 = ((_OutlineSoftness * _ScaleRatioA) * xlv_TEXCOORD5.y);
  outlineColor_14.xyz = _OutlineColor.xyz;
  faceColor_15 = (_FaceColor * xlv_COLOR0);
  outlineColor_14.w = (_OutlineColor.w * xlv_COLOR0.w);
  vec2 tmpvar_21;
  tmpvar_21.x = (xlv_TEXCOORD0.z + (_FaceUVSpeedX * _Time.y));
  tmpvar_21.y = (xlv_TEXCOORD0.w + (_FaceUVSpeedY * _Time.y));
  faceColor_15 = (faceColor_15 * texture2D (_FaceTex, tmpvar_21));
  vec2 tmpvar_22;
  tmpvar_22.x = (xlv_TEXCOORD0.z + (_OutlineUVSpeedX * _Time.y));
  tmpvar_22.y = (xlv_TEXCOORD0.w + (_OutlineUVSpeedY * _Time.y));
  outlineColor_14 = (outlineColor_14 * texture2D (_OutlineTex, tmpvar_22));
  vec4 faceColor_23;
  faceColor_23.w = faceColor_15.w;
  vec4 outlineColor_24;
  outlineColor_24.w = outlineColor_14.w;
  faceColor_23.xyz = (faceColor_15.xyz * faceColor_15.w);
  outlineColor_24.xyz = (outlineColor_14.xyz * outlineColor_14.w);
  faceColor_23 = (mix (faceColor_23, outlineColor_24, vec4((
    clamp ((tmpvar_18 + (tmpvar_19 * 0.5)), 0.0, 1.0)
   * 
    sqrt(min (1.0, tmpvar_19))
  ))) * (1.0 - clamp (
    (((tmpvar_18 - (tmpvar_19 * 0.5)) + (tmpvar_20 * 0.5)) / (1.0 + tmpvar_20))
  , 0.0, 1.0)));
  faceColor_15.w = faceColor_23.w;
  faceColor_15.xyz = (faceColor_23.xyz / max (faceColor_23.w, 0.0001));
  vec4 h_25;
  h_25 = tmpvar_17;
  float tmpvar_26;
  tmpvar_26 = (_ShaderFlags / 2.0);
  float tmpvar_27;
  tmpvar_27 = (fract(abs(tmpvar_26)) * 2.0);
  float tmpvar_28;
  if ((tmpvar_26 >= 0.0)) {
    tmpvar_28 = tmpvar_27;
  } else {
    tmpvar_28 = -(tmpvar_27);
  };
  h_25 = (tmpvar_17 + (xlv_TEXCOORD5.x + _BevelOffset));
  float tmpvar_29;
  tmpvar_29 = max (0.01, (_OutlineWidth + _BevelWidth));
  h_25 = (h_25 - 0.5);
  h_25 = (h_25 / tmpvar_29);
  vec4 tmpvar_30;
  tmpvar_30 = clamp ((h_25 + 0.5), 0.0, 1.0);
  h_25 = tmpvar_30;
  if (bool(float((tmpvar_28 >= 1.0)))) {
    h_25 = (1.0 - abs((
      (tmpvar_30 * 2.0)
     - 1.0)));
  };
  h_25 = (min (mix (h_25, 
    sin(((h_25 * 3.141592) / 2.0))
  , vec4(_BevelRoundness)), vec4((1.0 - _BevelClamp))) * ((_Bevel * tmpvar_29) * (_GradientScale * -2.0)));
  vec3 tmpvar_31;
  tmpvar_31.xy = vec2(1.0, 0.0);
  tmpvar_31.z = (h_25.y - h_25.x);
  vec3 tmpvar_32;
  tmpvar_32 = normalize(tmpvar_31);
  vec3 tmpvar_33;
  tmpvar_33.xy = vec2(0.0, -1.0);
  tmpvar_33.z = (h_25.w - h_25.z);
  vec3 tmpvar_34;
  tmpvar_34 = normalize(tmpvar_33);
  vec3 normal_35;
  normal_35.xy = ((texture2D (_BumpMap, xlv_TEXCOORD0.zw).wy * 2.0) - 1.0);
  normal_35.z = sqrt((1.0 - clamp (
    dot (normal_35.xy, normal_35.xy)
  , 0.0, 1.0)));
  bump_13 = (normal_35 * mix (_BumpFace, _BumpOutline, clamp (
    (tmpvar_18 + (tmpvar_19 * 0.5))
  , 0.0, 1.0)));
  vec3 tmpvar_36;
  tmpvar_36 = mix (vec3(0.0, 0.0, 1.0), bump_13, faceColor_23.www);
  bump_13 = tmpvar_36;
  tmpvar_9 = faceColor_15.xyz;
  tmpvar_10 = -(normalize((
    ((tmpvar_32.yzx * tmpvar_34.zxy) - (tmpvar_32.zxy * tmpvar_34.yzx))
   - tmpvar_36)));
  tmpvar_11 = 1.0;
  tmpvar_12 = faceColor_15.w;
  tmpvar_3 = tmpvar_9;
  tmpvar_5 = tmpvar_11;
  tmpvar_6 = tmpvar_12;
  vec4 tmpvar_37;
  tmpvar_37.w = 1.0;
  tmpvar_37.xyz = xlv_TEXCOORD4;
  vec3 tmpvar_38;
  tmpvar_38 = (_LightMatrix0 * tmpvar_37).xyz;
  worldN_2.x = dot (xlv_TEXCOORD1, tmpvar_10);
  worldN_2.y = dot (xlv_TEXCOORD2, tmpvar_10);
  worldN_2.z = dot (xlv_TEXCOORD3, tmpvar_10);
  tmpvar_4 = worldN_2;
  tmpvar_1 = (_LightColor0.xyz * (texture2D (_LightTextureB0, vec2(dot (tmpvar_38, tmpvar_38))).w * textureCube (_LightTexture0, tmpvar_38).w));
  vec4 c_39;
  vec4 c_40;
  c_40.xyz = (((faceColor_15.xyz * tmpvar_1) * max (0.0, 
    dot (worldN_2, tmpvar_7)
  )) + ((tmpvar_1 * _SpecColor.xyz) * pow (
    max (0.0, dot (worldN_2, normalize((tmpvar_7 + tmpvar_8))))
  , 
    (mix (_FaceShininess, _OutlineShininess, clamp ((tmpvar_18 + 
      (tmpvar_19 * 0.5)
    ), 0.0, 1.0)) * 128.0)
  )));
  c_40.w = tmpvar_12;
  c_39.w = c_40.w;
  c_39.xyz = c_40.xyz;
  gl_FragData[0] = c_39;
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 95 math
Keywords { "POINT_COOKIE" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
Matrix 10 [_EnvMatrix] 3
Matrix 4 [_Object2World] 3
Matrix 7 [_World2Object] 3
Matrix 0 [glstate_matrix_mvp]
Matrix 13 [glstate_matrix_projection] 2
Float 18 [_FaceDilate]
Vector 29 [_FaceTex_ST]
Float 24 [_GradientScale]
Vector 28 [_MainTex_ST]
Float 27 [_PerspectiveFilter]
Float 21 [_ScaleRatioA]
Float 25 [_ScaleX]
Float 26 [_ScaleY]
Vector 16 [_ScreenParams]
Float 22 [_VertexOffsetX]
Float 23 [_VertexOffsetY]
Float 20 [_WeightBold]
Float 19 [_WeightNormal]
Vector 15 [_WorldSpaceCameraPos]
Vector 17 [unity_WorldTransformParams]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   row_major float4x4 _EnvMatrix;
//   float _FaceDilate;
//   float4 _FaceTex_ST;
//   float _GradientScale;
//   float4 _MainTex_ST;
//   row_major float4x4 _Object2World;
//   float _PerspectiveFilter;
//   float _ScaleRatioA;
//   float _ScaleX;
//   float _ScaleY;
//   float4 _ScreenParams;
//   float _VertexOffsetX;
//   float _VertexOffsetY;
//   float _WeightBold;
//   float _WeightNormal;
//   row_major float4x4 _World2Object;
//   float3 _WorldSpaceCameraPos;
//   row_major float4x4 glstate_matrix_mvp;
//   row_major float4x4 glstate_matrix_projection;
//   float4 unity_WorldTransformParams;
//
//
// Registers:
//
//   Name                       Reg   Size
//   -------------------------- ----- ----
//   glstate_matrix_mvp         c0       4
//   _Object2World              c4       3
//   _World2Object              c7       3
//   _EnvMatrix                 c10      3
//   glstate_matrix_projection  c13      2
//   _WorldSpaceCameraPos       c15      1
//   _ScreenParams              c16      1
//   unity_WorldTransformParams c17      1
//   _FaceDilate                c18      1
//   _WeightNormal              c19      1
//   _WeightBold                c20      1
//   _ScaleRatioA               c21      1
//   _VertexOffsetX             c22      1
//   _VertexOffsetY             c23      1
//   _GradientScale             c24      1
//   _ScaleX                    c25      1
//   _ScaleY                    c26      1
//   _PerspectiveFilter         c27      1
//   _MainTex_ST                c28      1
//   _FaceTex_ST                c29      1
//

    vs_3_0
    def c30, 0, 1, 1.5, 0.5
    def c31, 0.00122070313, 5, 0, 0
    dcl_position v0
    dcl_tangent v1
    dcl_normal v2
    dcl_texcoord v3
    dcl_texcoord1 v4
    dcl_color v5
    dcl_position o0
    dcl_texcoord o1
    dcl_texcoord1 o2.xyz
    dcl_texcoord2 o3.xyz
    dcl_texcoord3 o4.xyz
    dcl_texcoord4 o5.xyz
    dcl_color o6
    dcl_texcoord5 o7.xy
    dcl_texcoord6 o8.xyz
    mov r0.xy, c30
    mad r1, c15.xyzx, r0.yyyx, r0.xxxy
    dp4 r2.x, c7, r1
    dp4 r2.y, c8, r1
    dp4 r2.z, c9, r1
    add r1.x, c22.x, v0.x
    add r1.y, c23.x, v0.y
    mov r1.zw, v0
    add r0.xzw, -r1.xyyz, r2.xyyz
    dp3 r0.x, v2, r0.xzww
    slt r0.z, -r0.x, r0.x
    slt r0.x, r0.x, -r0.x
    add r0.x, -r0.x, r0.z
    mul r0.xzw, r0.x, v2.xyyz
    mul r2.xyz, r0.z, c8.zxyw
    mad r2.xyz, c7.zxyw, r0.x, r2
    mad r0.xzw, c9.zyxy, r0.w, r2.xyyz
    dp3 r2.x, r0.xzww, r0.xzww
    rsq r2.x, r2.x
    mul r0.xzw, r0, r2.x
    dp4 r2.x, c4, r1
    dp4 r2.y, c5, r1
    dp4 r2.z, c6, r1
    add r3.xyz, -r2, c15
    mov o5.xyz, r2
    nrm r2.xyz, r3
    dp3 r2.x, r0.zwxw, r2
    mov r4.xy, c16
    mul r2.yz, r4.xxyw, c13.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c25.x
    rcp r5.x, r2.y
    mul r2.yz, r4.xxyw, c14.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c26.x
    rcp r5.y, r2.y
    dp4 r2.y, c3, r1
    mul r2.zw, r5.xyxy, r2.y
    mov o0.w, r2.y
    mul r2.yz, r2.xzww, r2.xzww
    add r2.y, r2.z, r2.y
    rsq r2.y, r2.y
    mul r2.z, c24.x, v4_abs.y
    mul r2.y, r2.y, r2.z
    mul r2.z, r2.y, c30.z
    add r0.y, r0.y, -c27.x
    mul r0.y, r0.y, r2.z
    mad r2.y, r2.y, c30.z, -r0.y
    mad o7.y, r2_abs.x, r2.y, r0.y
    sge r0.y, c30.x, v4.y
    mov r2.x, c19.x
    add r2.x, -r2.x, c20.x
    mad r0.y, r0.y, r2.x, c19.x
    mov r2.x, c18.x
    mul r2.x, r2.x, c21.x
    mul r2.x, r2.x, c30.w
    rcp r2.y, c24.x
    mad o7.x, r0.y, r2.y, r2.x
    dp3 o8.x, c10, r3
    dp3 o8.y, c11, r3
    dp3 o8.z, c12, r3
    dp4 o0.x, c0, r1
    dp4 o0.y, c1, r1
    dp4 o0.z, c2, r1
    mad o1.xy, v3, c28, c28.zwzw
    frc r0.y, v4.x
    add r1.x, -r0.y, v4.x
    mul r1.w, r0.y, c29.y
    mul r1.z, r1.x, c29.x
    mov r2.zw, c29
    mad o1.zw, r1, c31.xyxy, r2
    dp3 r1.z, c4, v1
    dp3 r1.x, c5, v1
    dp3 r1.y, c6, v1
    dp3 r0.y, r1, r1
    rsq r0.y, r0.y
    mul r1.xyz, r0.y, r1
    mov o2.x, r1.z
    mul r2.xyz, r0.xzww, r1
    mad r2.xyz, r0.wxzw, r1.yzxw, -r2
    mul r0.y, c17.w, v1.w
    mul r2.xyz, r0.y, r2
    mov o2.y, r2.x
    mov o2.z, r0.z
    mov o3.x, r1.x
    mov o4.x, r1.y
    mov o3.y, r2.y
    mov o4.y, r2.z
    mov o3.z, r0.w
    mov o4.z, r0.x
    mov o6, v5

// approximately 93 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 73 math
Keywords { "POINT_COOKIE" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
ConstBuffer "$Globals" 656
Matrix 336 [_EnvMatrix]
Float 224 [_FaceDilate]
Float 516 [_WeightNormal]
Float 520 [_WeightBold]
Float 524 [_ScaleRatioA]
Float 536 [_VertexOffsetX]
Float 540 [_VertexOffsetY]
Float 592 [_GradientScale]
Float 596 [_ScaleX]
Float 600 [_ScaleY]
Float 604 [_PerspectiveFilter]
Vector 624 [_MainTex_ST]
Vector 640 [_FaceTex_ST]
ConstBuffer "UnityPerCamera" 144
Vector 64 [_WorldSpaceCameraPos] 3
Vector 96 [_ScreenParams]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
Matrix 256 [_World2Object]
Vector 336 [unity_WorldTransformParams]
ConstBuffer "UnityPerFrame" 256
Matrix 0 [glstate_matrix_projection]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityPerDraw" 2
BindCB  "UnityPerFrame" 3
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// TANGENT                  0   xyzw        1     NONE   float   xyzw
// NORMAL                   0   xyz         2     NONE   float   xyz 
// TEXCOORD                 0   xyzw        3     NONE   float   xy  
// TEXCOORD                 1   xyzw        4     NONE   float   xy  
// TEXCOORD                 2   xyzw        5     NONE   float       
// TEXCOORD                 3   xyzw        6     NONE   float       
// COLOR                    0   xyzw        7     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float   xyz 
//
      vs_4_0
      dcl_constantbuffer cb0[41], immediateIndexed
      dcl_constantbuffer cb1[7], immediateIndexed
      dcl_constantbuffer cb2[22], immediateIndexed
      dcl_constantbuffer cb3[2], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v1.xyzw
      dcl_input v2.xyz
      dcl_input v3.xy
      dcl_input v4.xy
      dcl_input v7.xyzw
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xyzw
      dcl_output o2.xyz
      dcl_output o3.xyz
      dcl_output o4.xyz
      dcl_output o5.xyz
      dcl_output o6.xyzw
      dcl_output o7.xy
      dcl_output o8.xyz
      dcl_temps 4
   0: add r0.xy, v0.xyxx, cb0[33].zwzz
   1: mul r1.xyzw, r0.yyyy, cb2[1].xyzw
   2: mad r1.xyzw, cb2[0].xyzw, r0.xxxx, r1.xyzw
   3: mad r1.xyzw, cb2[2].xyzw, v0.zzzz, r1.xyzw
   4: mad o0.xyzw, cb2[3].xyzw, v0.wwww, r1.xyzw
   5: round_ni r0.w, v4.x
   6: mul r1.z, r0.w, cb0[40].x
   7: frc r0.w, v4.x
   8: mul r1.w, r0.w, cb0[40].y
   9: mad o1.zw, r1.zzzw, l(0.000000, 0.000000, 0.001221, 5.000000), cb0[40].zzzw
  10: mad o1.xy, v3.xyxx, cb0[39].xyxx, cb0[39].zwzz
  11: mul r1.xyz, cb1[4].yyyy, cb2[17].xyzx
  12: mad r1.xyz, cb2[16].xyzx, cb1[4].xxxx, r1.xyzx
  13: mad r1.xyz, cb2[18].xyzx, cb1[4].zzzz, r1.xyzx
  14: add r1.xyz, r1.xyzx, cb2[19].xyzx
  15: mov r0.z, v0.z
  16: add r1.xyz, -r0.xyzx, r1.xyzx
  17: dp3 r0.z, v2.xyzx, r1.xyzx
  18: lt r0.w, l(0.000000), r0.z
  19: lt r0.z, r0.z, l(0.000000)
  20: iadd r0.z, -r0.w, r0.z
  21: itof r0.z, r0.z
  22: mul r1.xyz, r0.zzzz, v2.xyzx
  23: mov r2.y, cb2[16].y
  24: mov r2.z, cb2[17].y
  25: mov r2.x, cb2[18].y
  26: mul r2.xyz, r1.yyyy, r2.xyzx
  27: mov r3.y, cb2[16].x
  28: mov r3.z, cb2[17].x
  29: mov r3.x, cb2[18].x
  30: mad r1.xyw, r3.xyxz, r1.xxxx, r2.xyxz
  31: mov r2.y, cb2[16].z
  32: mov r2.z, cb2[17].z
  33: mov r2.x, cb2[18].z
  34: mad r1.xyz, r2.xyzx, r1.zzzz, r1.xywx
  35: dp3 r0.z, r1.xyzx, r1.xyzx
  36: rsq r0.z, r0.z
  37: mul r1.xyz, r0.zzzz, r1.xyzx
  38: mov o2.z, r1.y
  39: mul r2.xyz, v1.yyyy, cb2[13].yzxy
  40: mad r2.xyz, cb2[12].yzxy, v1.xxxx, r2.xyzx
  41: mad r2.xyz, cb2[14].yzxy, v1.zzzz, r2.xyzx
  42: dp3 r0.z, r2.xyzx, r2.xyzx
  43: rsq r0.z, r0.z
  44: mul r2.xyz, r0.zzzz, r2.xyzx
  45: mul r3.xyz, r1.xyzx, r2.xyzx
  46: mad r3.xyz, r1.zxyz, r2.yzxy, -r3.xyzx
  47: mul r0.z, v1.w, cb2[21].w
  48: mul r3.xyz, r0.zzzz, r3.xyzx
  49: mov o2.y, r3.x
  50: mov o2.x, r2.z
  51: mov o3.x, r2.x
  52: mov o4.x, r2.y
  53: mov o3.z, r1.z
  54: mov o3.y, r3.y
  55: mov o4.y, r3.z
  56: mov o4.z, r1.x
  57: mul r2.xyz, r0.yyyy, cb2[13].xyzx
  58: mad r2.xyz, cb2[12].xyzx, r0.xxxx, r2.xyzx
  59: mad r2.xyz, cb2[14].xyzx, v0.zzzz, r2.xyzx
  60: mad r2.xyz, cb2[15].xyzx, v0.wwww, r2.xyzx
  61: mov o5.xyz, r2.xyzx
  62: add r2.xyz, -r2.xyzx, cb1[4].xyzx
  63: mov o6.xyzw, v7.xyzw
  64: mul r0.y, r0.y, cb2[1].w
  65: mad r0.x, cb2[0].w, r0.x, r0.y
  66: mad r0.x, cb2[2].w, v0.z, r0.x
  67: mad r0.x, cb2[3].w, v0.w, r0.x
  68: mul r0.yz, cb1[6].yyyy, cb3[1].xxyx
  69: mad r0.yz, cb3[0].xxyx, cb1[6].xxxx, r0.yyzy
  70: mul r0.yz, r0.yyzy, cb0[37].yyzy
  71: div r0.xy, r0.xxxx, r0.yzyy
  72: dp2 r0.x, r0.xyxx, r0.xyxx
  73: rsq r0.x, r0.x
  74: mul r0.y, |v4.y|, cb0[37].x
  75: mul r0.x, r0.x, r0.y
  76: mul r0.y, r0.x, l(1.500000)
  77: add r0.z, -cb0[37].w, l(1.000000)
  78: mul r0.y, r0.z, r0.y
  79: mad r0.x, r0.x, l(1.500000), -r0.y
  80: dp3 r0.z, r2.xyzx, r2.xyzx
  81: rsq r0.z, r0.z
  82: mul r3.xyz, r0.zzzz, r2.xyzx
  83: dp3 r0.z, r1.yzxy, r3.xyzx
  84: mad o7.y, |r0.z|, r0.x, r0.y
  85: ge r0.x, l(0.000000), v4.y
  86: and r0.x, r0.x, l(0x3f800000)
  87: add r0.y, -cb0[32].y, cb0[32].z
  88: mad r0.x, r0.x, r0.y, cb0[32].y
  89: div r0.x, r0.x, cb0[37].x
  90: mul r0.y, cb0[14].x, cb0[32].w
  91: mad o7.x, r0.y, l(0.500000), r0.x
  92: mul r0.xyz, r2.yyyy, cb0[22].xyzx
  93: mad r0.xyz, cb0[21].xyzx, r2.xxxx, r0.xyzx
  94: mad o8.xyz, cb0[23].xyzx, r2.zzzz, r0.xyzx
  95: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
// Stats: 131 math, 9 textures, 2 branches
Keywords { "DIRECTIONAL_COOKIE" }
"#version 120

#ifdef VERTEX
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _ScreenParams;

uniform mat4 _Object2World;
uniform mat4 _World2Object;
uniform vec4 unity_WorldTransformParams;

uniform float _FaceDilate;
uniform mat4 _EnvMatrix;
uniform float _WeightNormal;
uniform float _WeightBold;
uniform float _ScaleRatioA;
uniform float _VertexOffsetX;
uniform float _VertexOffsetY;
uniform float _GradientScale;
uniform float _ScaleX;
uniform float _ScaleY;
uniform float _PerspectiveFilter;
uniform vec4 _MainTex_ST;
uniform vec4 _FaceTex_ST;
attribute vec4 TANGENT;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
varying vec3 xlv_TEXCOORD6;
void main ()
{
  vec4 tmpvar_1;
  vec4 tmpvar_2;
  vec3 tmpvar_3;
  tmpvar_2.zw = gl_Vertex.zw;
  vec2 tmpvar_4;
  float scale_5;
  vec2 pixelSize_6;
  tmpvar_2.x = (gl_Vertex.x + _VertexOffsetX);
  tmpvar_2.y = (gl_Vertex.y + _VertexOffsetY);
  vec4 tmpvar_7;
  tmpvar_7.w = 1.0;
  tmpvar_7.xyz = _WorldSpaceCameraPos;
  tmpvar_3 = (gl_Normal * sign(dot (gl_Normal, 
    ((_World2Object * tmpvar_7).xyz - tmpvar_2.xyz)
  )));
  vec2 tmpvar_8;
  tmpvar_8.x = _ScaleX;
  tmpvar_8.y = _ScaleY;
  mat2 tmpvar_9;
  tmpvar_9[0] = gl_ProjectionMatrix[0].xy;
  tmpvar_9[1] = gl_ProjectionMatrix[1].xy;
  pixelSize_6 = ((gl_ModelViewProjectionMatrix * tmpvar_2).ww / (tmpvar_8 * (tmpvar_9 * _ScreenParams.xy)));
  scale_5 = (inversesqrt(dot (pixelSize_6, pixelSize_6)) * ((
    abs(gl_MultiTexCoord1.y)
   * _GradientScale) * 1.5));
  vec4 v_10;
  float tmpvar_11;
  tmpvar_11 = _World2Object[0].x;
  v_10.x = tmpvar_11;
  float tmpvar_12;
  tmpvar_12 = _World2Object[1].x;
  v_10.y = tmpvar_12;
  float tmpvar_13;
  tmpvar_13 = _World2Object[2].x;
  v_10.z = tmpvar_13;
  float tmpvar_14;
  tmpvar_14 = _World2Object[3].x;
  v_10.w = tmpvar_14;
  vec4 v_15;
  float tmpvar_16;
  tmpvar_16 = _World2Object[0].y;
  v_15.x = tmpvar_16;
  float tmpvar_17;
  tmpvar_17 = _World2Object[1].y;
  v_15.y = tmpvar_17;
  float tmpvar_18;
  tmpvar_18 = _World2Object[2].y;
  v_15.z = tmpvar_18;
  float tmpvar_19;
  tmpvar_19 = _World2Object[3].y;
  v_15.w = tmpvar_19;
  vec4 v_20;
  float tmpvar_21;
  tmpvar_21 = _World2Object[0].z;
  v_20.x = tmpvar_21;
  float tmpvar_22;
  tmpvar_22 = _World2Object[1].z;
  v_20.y = tmpvar_22;
  float tmpvar_23;
  tmpvar_23 = _World2Object[2].z;
  v_20.z = tmpvar_23;
  float tmpvar_24;
  tmpvar_24 = _World2Object[3].z;
  v_20.w = tmpvar_24;
  float tmpvar_25;
  tmpvar_25 = mix ((scale_5 * (1.0 - _PerspectiveFilter)), scale_5, abs(dot (
    normalize((((v_10.xyz * tmpvar_3.x) + (v_15.xyz * tmpvar_3.y)) + (v_20.xyz * tmpvar_3.z)))
  , 
    normalize((_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz))
  )));
  scale_5 = tmpvar_25;
  tmpvar_4.y = tmpvar_25;
  tmpvar_4.x = ((mix (_WeightNormal, _WeightBold, 
    float((0.0 >= gl_MultiTexCoord1.y))
  ) / _GradientScale) + ((_FaceDilate * _ScaleRatioA) * 0.5));
  vec2 tmpvar_26;
  tmpvar_26.x = ((floor(gl_MultiTexCoord1.x) * 5.0) / 4096.0);
  tmpvar_26.y = (fract(gl_MultiTexCoord1.x) * 5.0);
  mat3 tmpvar_27;
  tmpvar_27[0] = _EnvMatrix[0].xyz;
  tmpvar_27[1] = _EnvMatrix[1].xyz;
  tmpvar_27[2] = _EnvMatrix[2].xyz;
  tmpvar_1.xy = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  tmpvar_1.zw = ((tmpvar_26 * _FaceTex_ST.xy) + _FaceTex_ST.zw);
  vec4 v_28;
  v_28.x = tmpvar_11;
  v_28.y = tmpvar_12;
  v_28.z = tmpvar_13;
  v_28.w = tmpvar_14;
  vec4 v_29;
  v_29.x = tmpvar_16;
  v_29.y = tmpvar_17;
  v_29.z = tmpvar_18;
  v_29.w = tmpvar_19;
  vec4 v_30;
  v_30.x = tmpvar_21;
  v_30.y = tmpvar_22;
  v_30.z = tmpvar_23;
  v_30.w = tmpvar_24;
  vec3 tmpvar_31;
  tmpvar_31 = normalize(((
    (v_28.xyz * tmpvar_3.x)
   + 
    (v_29.xyz * tmpvar_3.y)
  ) + (v_30.xyz * tmpvar_3.z)));
  mat3 tmpvar_32;
  tmpvar_32[0] = _Object2World[0].xyz;
  tmpvar_32[1] = _Object2World[1].xyz;
  tmpvar_32[2] = _Object2World[2].xyz;
  vec3 tmpvar_33;
  tmpvar_33 = normalize((tmpvar_32 * TANGENT.xyz));
  vec3 tmpvar_34;
  tmpvar_34 = (((tmpvar_31.yzx * tmpvar_33.zxy) - (tmpvar_31.zxy * tmpvar_33.yzx)) * (TANGENT.w * unity_WorldTransformParams.w));
  vec3 tmpvar_35;
  tmpvar_35.x = tmpvar_33.x;
  tmpvar_35.y = tmpvar_34.x;
  tmpvar_35.z = tmpvar_31.x;
  vec3 tmpvar_36;
  tmpvar_36.x = tmpvar_33.y;
  tmpvar_36.y = tmpvar_34.y;
  tmpvar_36.z = tmpvar_31.y;
  vec3 tmpvar_37;
  tmpvar_37.x = tmpvar_33.z;
  tmpvar_37.y = tmpvar_34.z;
  tmpvar_37.z = tmpvar_31.z;
  gl_Position = (gl_ModelViewProjectionMatrix * tmpvar_2);
  xlv_TEXCOORD0 = tmpvar_1;
  xlv_TEXCOORD1 = tmpvar_35;
  xlv_TEXCOORD2 = tmpvar_36;
  xlv_TEXCOORD3 = tmpvar_37;
  xlv_TEXCOORD4 = (_Object2World * tmpvar_2).xyz;
  xlv_COLOR0 = gl_Color;
  xlv_TEXCOORD5 = tmpvar_4;
  xlv_TEXCOORD6 = (tmpvar_27 * (_WorldSpaceCameraPos - (_Object2World * tmpvar_2).xyz));
}


#endif
#ifdef FRAGMENT
uniform vec4 _Time;
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _WorldSpaceLightPos0;
uniform vec4 _LightColor0;
uniform vec4 _SpecColor;
uniform sampler2D _LightTexture0;
uniform mat4 _LightMatrix0;
uniform sampler2D _FaceTex;
uniform float _FaceUVSpeedX;
uniform float _FaceUVSpeedY;
uniform vec4 _FaceColor;
uniform float _OutlineSoftness;
uniform sampler2D _OutlineTex;
uniform float _OutlineUVSpeedX;
uniform float _OutlineUVSpeedY;
uniform vec4 _OutlineColor;
uniform float _OutlineWidth;
uniform float _Bevel;
uniform float _BevelOffset;
uniform float _BevelWidth;
uniform float _BevelClamp;
uniform float _BevelRoundness;
uniform sampler2D _BumpMap;
uniform float _BumpOutline;
uniform float _BumpFace;
uniform float _ShaderFlags;
uniform float _ScaleRatioA;
uniform sampler2D _MainTex;
uniform float _TextureWidth;
uniform float _TextureHeight;
uniform float _GradientScale;
uniform float _FaceShininess;
uniform float _OutlineShininess;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec3 xlv_TEXCOORD2;
varying vec3 xlv_TEXCOORD3;
varying vec3 xlv_TEXCOORD4;
varying vec4 xlv_COLOR0;
varying vec2 xlv_TEXCOORD5;
void main ()
{
  vec3 tmpvar_1;
  vec3 worldN_2;
  vec3 tmpvar_3;
  vec3 tmpvar_4;
  float tmpvar_5;
  float tmpvar_6;
  vec3 tmpvar_7;
  tmpvar_7 = normalize((_WorldSpaceCameraPos - xlv_TEXCOORD4));
  tmpvar_3 = vec3(0.0, 0.0, 0.0);
  tmpvar_6 = 0.0;
  tmpvar_5 = 0.0;
  vec3 tmpvar_8;
  vec3 tmpvar_9;
  float tmpvar_10;
  float tmpvar_11;
  tmpvar_8 = tmpvar_3;
  tmpvar_9 = tmpvar_4;
  tmpvar_10 = tmpvar_5;
  tmpvar_11 = tmpvar_6;
  vec3 bump_12;
  vec4 outlineColor_13;
  vec4 faceColor_14;
  vec3 tmpvar_15;
  tmpvar_15.z = 0.0;
  tmpvar_15.x = (1.0/(_TextureWidth));
  tmpvar_15.y = (1.0/(_TextureHeight));
  vec4 tmpvar_16;
  tmpvar_16.x = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_15.xz)).w;
  tmpvar_16.y = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_15.xz)).w;
  tmpvar_16.z = texture2D (_MainTex, (xlv_TEXCOORD0.xy - tmpvar_15.zy)).w;
  tmpvar_16.w = texture2D (_MainTex, (xlv_TEXCOORD0.xy + tmpvar_15.zy)).w;
  float tmpvar_17;
  tmpvar_17 = (((
    (0.5 - texture2D (_MainTex, xlv_TEXCOORD0.xy).w)
   - xlv_TEXCOORD5.x) * xlv_TEXCOORD5.y) + 0.5);
  float tmpvar_18;
  tmpvar_18 = ((_OutlineWidth * _ScaleRatioA) * xlv_TEXCOORD5.y);
  float tmpvar_19;
  tmpvar_19 = ((_OutlineSoftness * _ScaleRatioA) * xlv_TEXCOORD5.y);
  outlineColor_13.xyz = _OutlineColor.xyz;
  faceColor_14 = (_FaceColor * xlv_COLOR0);
  outlineColor_13.w = (_OutlineColor.w * xlv_COLOR0.w);
  vec2 tmpvar_20;
  tmpvar_20.x = (xlv_TEXCOORD0.z + (_FaceUVSpeedX * _Time.y));
  tmpvar_20.y = (xlv_TEXCOORD0.w + (_FaceUVSpeedY * _Time.y));
  faceColor_14 = (faceColor_14 * texture2D (_FaceTex, tmpvar_20));
  vec2 tmpvar_21;
  tmpvar_21.x = (xlv_TEXCOORD0.z + (_OutlineUVSpeedX * _Time.y));
  tmpvar_21.y = (xlv_TEXCOORD0.w + (_OutlineUVSpeedY * _Time.y));
  outlineColor_13 = (outlineColor_13 * texture2D (_OutlineTex, tmpvar_21));
  vec4 faceColor_22;
  faceColor_22.w = faceColor_14.w;
  vec4 outlineColor_23;
  outlineColor_23.w = outlineColor_13.w;
  faceColor_22.xyz = (faceColor_14.xyz * faceColor_14.w);
  outlineColor_23.xyz = (outlineColor_13.xyz * outlineColor_13.w);
  faceColor_22 = (mix (faceColor_22, outlineColor_23, vec4((
    clamp ((tmpvar_17 + (tmpvar_18 * 0.5)), 0.0, 1.0)
   * 
    sqrt(min (1.0, tmpvar_18))
  ))) * (1.0 - clamp (
    (((tmpvar_17 - (tmpvar_18 * 0.5)) + (tmpvar_19 * 0.5)) / (1.0 + tmpvar_19))
  , 0.0, 1.0)));
  faceColor_14.w = faceColor_22.w;
  faceColor_14.xyz = (faceColor_22.xyz / max (faceColor_22.w, 0.0001));
  vec4 h_24;
  h_24 = tmpvar_16;
  float tmpvar_25;
  tmpvar_25 = (_ShaderFlags / 2.0);
  float tmpvar_26;
  tmpvar_26 = (fract(abs(tmpvar_25)) * 2.0);
  float tmpvar_27;
  if ((tmpvar_25 >= 0.0)) {
    tmpvar_27 = tmpvar_26;
  } else {
    tmpvar_27 = -(tmpvar_26);
  };
  h_24 = (tmpvar_16 + (xlv_TEXCOORD5.x + _BevelOffset));
  float tmpvar_28;
  tmpvar_28 = max (0.01, (_OutlineWidth + _BevelWidth));
  h_24 = (h_24 - 0.5);
  h_24 = (h_24 / tmpvar_28);
  vec4 tmpvar_29;
  tmpvar_29 = clamp ((h_24 + 0.5), 0.0, 1.0);
  h_24 = tmpvar_29;
  if (bool(float((tmpvar_27 >= 1.0)))) {
    h_24 = (1.0 - abs((
      (tmpvar_29 * 2.0)
     - 1.0)));
  };
  h_24 = (min (mix (h_24, 
    sin(((h_24 * 3.141592) / 2.0))
  , vec4(_BevelRoundness)), vec4((1.0 - _BevelClamp))) * ((_Bevel * tmpvar_28) * (_GradientScale * -2.0)));
  vec3 tmpvar_30;
  tmpvar_30.xy = vec2(1.0, 0.0);
  tmpvar_30.z = (h_24.y - h_24.x);
  vec3 tmpvar_31;
  tmpvar_31 = normalize(tmpvar_30);
  vec3 tmpvar_32;
  tmpvar_32.xy = vec2(0.0, -1.0);
  tmpvar_32.z = (h_24.w - h_24.z);
  vec3 tmpvar_33;
  tmpvar_33 = normalize(tmpvar_32);
  vec3 normal_34;
  normal_34.xy = ((texture2D (_BumpMap, xlv_TEXCOORD0.zw).wy * 2.0) - 1.0);
  normal_34.z = sqrt((1.0 - clamp (
    dot (normal_34.xy, normal_34.xy)
  , 0.0, 1.0)));
  bump_12 = (normal_34 * mix (_BumpFace, _BumpOutline, clamp (
    (tmpvar_17 + (tmpvar_18 * 0.5))
  , 0.0, 1.0)));
  vec3 tmpvar_35;
  tmpvar_35 = mix (vec3(0.0, 0.0, 1.0), bump_12, faceColor_22.www);
  bump_12 = tmpvar_35;
  tmpvar_8 = faceColor_14.xyz;
  tmpvar_9 = -(normalize((
    ((tmpvar_31.yzx * tmpvar_33.zxy) - (tmpvar_31.zxy * tmpvar_33.yzx))
   - tmpvar_35)));
  tmpvar_10 = 1.0;
  tmpvar_11 = faceColor_14.w;
  tmpvar_3 = tmpvar_8;
  tmpvar_5 = tmpvar_10;
  tmpvar_6 = tmpvar_11;
  vec4 tmpvar_36;
  tmpvar_36.w = 1.0;
  tmpvar_36.xyz = xlv_TEXCOORD4;
  worldN_2.x = dot (xlv_TEXCOORD1, tmpvar_9);
  worldN_2.y = dot (xlv_TEXCOORD2, tmpvar_9);
  worldN_2.z = dot (xlv_TEXCOORD3, tmpvar_9);
  tmpvar_4 = worldN_2;
  tmpvar_1 = (_LightColor0.xyz * texture2D (_LightTexture0, (_LightMatrix0 * tmpvar_36).xy).w);
  vec4 c_37;
  vec4 c_38;
  c_38.xyz = (((faceColor_14.xyz * tmpvar_1) * max (0.0, 
    dot (worldN_2, _WorldSpaceLightPos0.xyz)
  )) + ((tmpvar_1 * _SpecColor.xyz) * pow (
    max (0.0, dot (worldN_2, normalize((_WorldSpaceLightPos0.xyz + tmpvar_7))))
  , 
    (mix (_FaceShininess, _OutlineShininess, clamp ((tmpvar_17 + 
      (tmpvar_18 * 0.5)
    ), 0.0, 1.0)) * 128.0)
  )));
  c_38.w = tmpvar_11;
  c_37.w = c_38.w;
  c_37.xyz = c_38.xyz;
  gl_FragData[0] = c_37;
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 95 math
Keywords { "DIRECTIONAL_COOKIE" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
Matrix 10 [_EnvMatrix] 3
Matrix 4 [_Object2World] 3
Matrix 7 [_World2Object] 3
Matrix 0 [glstate_matrix_mvp]
Matrix 13 [glstate_matrix_projection] 2
Float 18 [_FaceDilate]
Vector 29 [_FaceTex_ST]
Float 24 [_GradientScale]
Vector 28 [_MainTex_ST]
Float 27 [_PerspectiveFilter]
Float 21 [_ScaleRatioA]
Float 25 [_ScaleX]
Float 26 [_ScaleY]
Vector 16 [_ScreenParams]
Float 22 [_VertexOffsetX]
Float 23 [_VertexOffsetY]
Float 20 [_WeightBold]
Float 19 [_WeightNormal]
Vector 15 [_WorldSpaceCameraPos]
Vector 17 [unity_WorldTransformParams]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   row_major float4x4 _EnvMatrix;
//   float _FaceDilate;
//   float4 _FaceTex_ST;
//   float _GradientScale;
//   float4 _MainTex_ST;
//   row_major float4x4 _Object2World;
//   float _PerspectiveFilter;
//   float _ScaleRatioA;
//   float _ScaleX;
//   float _ScaleY;
//   float4 _ScreenParams;
//   float _VertexOffsetX;
//   float _VertexOffsetY;
//   float _WeightBold;
//   float _WeightNormal;
//   row_major float4x4 _World2Object;
//   float3 _WorldSpaceCameraPos;
//   row_major float4x4 glstate_matrix_mvp;
//   row_major float4x4 glstate_matrix_projection;
//   float4 unity_WorldTransformParams;
//
//
// Registers:
//
//   Name                       Reg   Size
//   -------------------------- ----- ----
//   glstate_matrix_mvp         c0       4
//   _Object2World              c4       3
//   _World2Object              c7       3
//   _EnvMatrix                 c10      3
//   glstate_matrix_projection  c13      2
//   _WorldSpaceCameraPos       c15      1
//   _ScreenParams              c16      1
//   unity_WorldTransformParams c17      1
//   _FaceDilate                c18      1
//   _WeightNormal              c19      1
//   _WeightBold                c20      1
//   _ScaleRatioA               c21      1
//   _VertexOffsetX             c22      1
//   _VertexOffsetY             c23      1
//   _GradientScale             c24      1
//   _ScaleX                    c25      1
//   _ScaleY                    c26      1
//   _PerspectiveFilter         c27      1
//   _MainTex_ST                c28      1
//   _FaceTex_ST                c29      1
//

    vs_3_0
    def c30, 0, 1, 1.5, 0.5
    def c31, 0.00122070313, 5, 0, 0
    dcl_position v0
    dcl_tangent v1
    dcl_normal v2
    dcl_texcoord v3
    dcl_texcoord1 v4
    dcl_color v5
    dcl_position o0
    dcl_texcoord o1
    dcl_texcoord1 o2.xyz
    dcl_texcoord2 o3.xyz
    dcl_texcoord3 o4.xyz
    dcl_texcoord4 o5.xyz
    dcl_color o6
    dcl_texcoord5 o7.xy
    dcl_texcoord6 o8.xyz
    mov r0.xy, c30
    mad r1, c15.xyzx, r0.yyyx, r0.xxxy
    dp4 r2.x, c7, r1
    dp4 r2.y, c8, r1
    dp4 r2.z, c9, r1
    add r1.x, c22.x, v0.x
    add r1.y, c23.x, v0.y
    mov r1.zw, v0
    add r0.xzw, -r1.xyyz, r2.xyyz
    dp3 r0.x, v2, r0.xzww
    slt r0.z, -r0.x, r0.x
    slt r0.x, r0.x, -r0.x
    add r0.x, -r0.x, r0.z
    mul r0.xzw, r0.x, v2.xyyz
    mul r2.xyz, r0.z, c8.zxyw
    mad r2.xyz, c7.zxyw, r0.x, r2
    mad r0.xzw, c9.zyxy, r0.w, r2.xyyz
    dp3 r2.x, r0.xzww, r0.xzww
    rsq r2.x, r2.x
    mul r0.xzw, r0, r2.x
    dp4 r2.x, c4, r1
    dp4 r2.y, c5, r1
    dp4 r2.z, c6, r1
    add r3.xyz, -r2, c15
    mov o5.xyz, r2
    nrm r2.xyz, r3
    dp3 r2.x, r0.zwxw, r2
    mov r4.xy, c16
    mul r2.yz, r4.xxyw, c13.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c25.x
    rcp r5.x, r2.y
    mul r2.yz, r4.xxyw, c14.xxyw
    add r2.y, r2.z, r2.y
    mul r2.y, r2.y, c26.x
    rcp r5.y, r2.y
    dp4 r2.y, c3, r1
    mul r2.zw, r5.xyxy, r2.y
    mov o0.w, r2.y
    mul r2.yz, r2.xzww, r2.xzww
    add r2.y, r2.z, r2.y
    rsq r2.y, r2.y
    mul r2.z, c24.x, v4_abs.y
    mul r2.y, r2.y, r2.z
    mul r2.z, r2.y, c30.z
    add r0.y, r0.y, -c27.x
    mul r0.y, r0.y, r2.z
    mad r2.y, r2.y, c30.z, -r0.y
    mad o7.y, r2_abs.x, r2.y, r0.y
    sge r0.y, c30.x, v4.y
    mov r2.x, c19.x
    add r2.x, -r2.x, c20.x
    mad r0.y, r0.y, r2.x, c19.x
    mov r2.x, c18.x
    mul r2.x, r2.x, c21.x
    mul r2.x, r2.x, c30.w
    rcp r2.y, c24.x
    mad o7.x, r0.y, r2.y, r2.x
    dp3 o8.x, c10, r3
    dp3 o8.y, c11, r3
    dp3 o8.z, c12, r3
    dp4 o0.x, c0, r1
    dp4 o0.y, c1, r1
    dp4 o0.z, c2, r1
    mad o1.xy, v3, c28, c28.zwzw
    frc r0.y, v4.x
    add r1.x, -r0.y, v4.x
    mul r1.w, r0.y, c29.y
    mul r1.z, r1.x, c29.x
    mov r2.zw, c29
    mad o1.zw, r1, c31.xyxy, r2
    dp3 r1.z, c4, v1
    dp3 r1.x, c5, v1
    dp3 r1.y, c6, v1
    dp3 r0.y, r1, r1
    rsq r0.y, r0.y
    mul r1.xyz, r0.y, r1
    mov o2.x, r1.z
    mul r2.xyz, r0.xzww, r1
    mad r2.xyz, r0.wxzw, r1.yzxw, -r2
    mul r0.y, c17.w, v1.w
    mul r2.xyz, r0.y, r2
    mov o2.y, r2.x
    mov o2.z, r0.z
    mov o3.x, r1.x
    mov o4.x, r1.y
    mov o3.y, r2.y
    mov o4.y, r2.z
    mov o3.z, r0.w
    mov o4.z, r0.x
    mov o6, v5

// approximately 93 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 73 math
Keywords { "DIRECTIONAL_COOKIE" }
Bind "vertex" Vertex
Bind "color" Color
Bind "normal" Normal
Bind "texcoord" TexCoord0
Bind "texcoord1" TexCoord1
Bind "tangent" TexCoord4
ConstBuffer "$Globals" 656
Matrix 336 [_EnvMatrix]
Float 224 [_FaceDilate]
Float 516 [_WeightNormal]
Float 520 [_WeightBold]
Float 524 [_ScaleRatioA]
Float 536 [_VertexOffsetX]
Float 540 [_VertexOffsetY]
Float 592 [_GradientScale]
Float 596 [_ScaleX]
Float 600 [_ScaleY]
Float 604 [_PerspectiveFilter]
Vector 624 [_MainTex_ST]
Vector 640 [_FaceTex_ST]
ConstBuffer "UnityPerCamera" 144
Vector 64 [_WorldSpaceCameraPos] 3
Vector 96 [_ScreenParams]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
Matrix 256 [_World2Object]
Vector 336 [unity_WorldTransformParams]
ConstBuffer "UnityPerFrame" 256
Matrix 0 [glstate_matrix_projection]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityPerDraw" 2
BindCB  "UnityPerFrame" 3
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// TANGENT                  0   xyzw        1     NONE   float   xyzw
// NORMAL                   0   xyz         2     NONE   float   xyz 
// TEXCOORD                 0   xyzw        3     NONE   float   xy  
// TEXCOORD                 1   xyzw        4     NONE   float   xy  
// TEXCOORD                 2   xyzw        5     NONE   float       
// TEXCOORD                 3   xyzw        6     NONE   float       
// COLOR                    0   xyzw        7     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float   xyz 
//
      vs_4_0
      dcl_constantbuffer cb0[41], immediateIndexed
      dcl_constantbuffer cb1[7], immediateIndexed
      dcl_constantbuffer cb2[22], immediateIndexed
      dcl_constantbuffer cb3[2], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v1.xyzw
      dcl_input v2.xyz
      dcl_input v3.xy
      dcl_input v4.xy
      dcl_input v7.xyzw
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xyzw
      dcl_output o2.xyz
      dcl_output o3.xyz
      dcl_output o4.xyz
      dcl_output o5.xyz
      dcl_output o6.xyzw
      dcl_output o7.xy
      dcl_output o8.xyz
      dcl_temps 4
   0: add r0.xy, v0.xyxx, cb0[33].zwzz
   1: mul r1.xyzw, r0.yyyy, cb2[1].xyzw
   2: mad r1.xyzw, cb2[0].xyzw, r0.xxxx, r1.xyzw
   3: mad r1.xyzw, cb2[2].xyzw, v0.zzzz, r1.xyzw
   4: mad o0.xyzw, cb2[3].xyzw, v0.wwww, r1.xyzw
   5: round_ni r0.w, v4.x
   6: mul r1.z, r0.w, cb0[40].x
   7: frc r0.w, v4.x
   8: mul r1.w, r0.w, cb0[40].y
   9: mad o1.zw, r1.zzzw, l(0.000000, 0.000000, 0.001221, 5.000000), cb0[40].zzzw
  10: mad o1.xy, v3.xyxx, cb0[39].xyxx, cb0[39].zwzz
  11: mul r1.xyz, cb1[4].yyyy, cb2[17].xyzx
  12: mad r1.xyz, cb2[16].xyzx, cb1[4].xxxx, r1.xyzx
  13: mad r1.xyz, cb2[18].xyzx, cb1[4].zzzz, r1.xyzx
  14: add r1.xyz, r1.xyzx, cb2[19].xyzx
  15: mov r0.z, v0.z
  16: add r1.xyz, -r0.xyzx, r1.xyzx
  17: dp3 r0.z, v2.xyzx, r1.xyzx
  18: lt r0.w, l(0.000000), r0.z
  19: lt r0.z, r0.z, l(0.000000)
  20: iadd r0.z, -r0.w, r0.z
  21: itof r0.z, r0.z
  22: mul r1.xyz, r0.zzzz, v2.xyzx
  23: mov r2.y, cb2[16].y
  24: mov r2.z, cb2[17].y
  25: mov r2.x, cb2[18].y
  26: mul r2.xyz, r1.yyyy, r2.xyzx
  27: mov r3.y, cb2[16].x
  28: mov r3.z, cb2[17].x
  29: mov r3.x, cb2[18].x
  30: mad r1.xyw, r3.xyxz, r1.xxxx, r2.xyxz
  31: mov r2.y, cb2[16].z
  32: mov r2.z, cb2[17].z
  33: mov r2.x, cb2[18].z
  34: mad r1.xyz, r2.xyzx, r1.zzzz, r1.xywx
  35: dp3 r0.z, r1.xyzx, r1.xyzx
  36: rsq r0.z, r0.z
  37: mul r1.xyz, r0.zzzz, r1.xyzx
  38: mov o2.z, r1.y
  39: mul r2.xyz, v1.yyyy, cb2[13].yzxy
  40: mad r2.xyz, cb2[12].yzxy, v1.xxxx, r2.xyzx
  41: mad r2.xyz, cb2[14].yzxy, v1.zzzz, r2.xyzx
  42: dp3 r0.z, r2.xyzx, r2.xyzx
  43: rsq r0.z, r0.z
  44: mul r2.xyz, r0.zzzz, r2.xyzx
  45: mul r3.xyz, r1.xyzx, r2.xyzx
  46: mad r3.xyz, r1.zxyz, r2.yzxy, -r3.xyzx
  47: mul r0.z, v1.w, cb2[21].w
  48: mul r3.xyz, r0.zzzz, r3.xyzx
  49: mov o2.y, r3.x
  50: mov o2.x, r2.z
  51: mov o3.x, r2.x
  52: mov o4.x, r2.y
  53: mov o3.z, r1.z
  54: mov o3.y, r3.y
  55: mov o4.y, r3.z
  56: mov o4.z, r1.x
  57: mul r2.xyz, r0.yyyy, cb2[13].xyzx
  58: mad r2.xyz, cb2[12].xyzx, r0.xxxx, r2.xyzx
  59: mad r2.xyz, cb2[14].xyzx, v0.zzzz, r2.xyzx
  60: mad r2.xyz, cb2[15].xyzx, v0.wwww, r2.xyzx
  61: mov o5.xyz, r2.xyzx
  62: add r2.xyz, -r2.xyzx, cb1[4].xyzx
  63: mov o6.xyzw, v7.xyzw
  64: mul r0.y, r0.y, cb2[1].w
  65: mad r0.x, cb2[0].w, r0.x, r0.y
  66: mad r0.x, cb2[2].w, v0.z, r0.x
  67: mad r0.x, cb2[3].w, v0.w, r0.x
  68: mul r0.yz, cb1[6].yyyy, cb3[1].xxyx
  69: mad r0.yz, cb3[0].xxyx, cb1[6].xxxx, r0.yyzy
  70: mul r0.yz, r0.yyzy, cb0[37].yyzy
  71: div r0.xy, r0.xxxx, r0.yzyy
  72: dp2 r0.x, r0.xyxx, r0.xyxx
  73: rsq r0.x, r0.x
  74: mul r0.y, |v4.y|, cb0[37].x
  75: mul r0.x, r0.x, r0.y
  76: mul r0.y, r0.x, l(1.500000)
  77: add r0.z, -cb0[37].w, l(1.000000)
  78: mul r0.y, r0.z, r0.y
  79: mad r0.x, r0.x, l(1.500000), -r0.y
  80: dp3 r0.z, r2.xyzx, r2.xyzx
  81: rsq r0.z, r0.z
  82: mul r3.xyz, r0.zzzz, r2.xyzx
  83: dp3 r0.z, r1.yzxy, r3.xyzx
  84: mad o7.y, |r0.z|, r0.x, r0.y
  85: ge r0.x, l(0.000000), v4.y
  86: and r0.x, r0.x, l(0x3f800000)
  87: add r0.y, -cb0[32].y, cb0[32].z
  88: mad r0.x, r0.x, r0.y, cb0[32].y
  89: div r0.x, r0.x, cb0[37].x
  90: mul r0.y, cb0[14].x, cb0[32].w
  91: mad o7.x, r0.y, l(0.500000), r0.x
  92: mul r0.xyz, r2.yyyy, cb0[22].xyzx
  93: mad r0.xyz, cb0[21].xyzx, r2.xxxx, r0.xyzx
  94: mad o8.xyz, cb0[23].xyzx, r2.zzzz, r0.xyzx
  95: ret 
// Approximately 0 instruction slots used
"
}
}
Program "fp" {
SubProgram "opengl " {
Keywords { "POINT" }
"// shader disassembly not supported on opengl"
}
SubProgram "d3d9 " {
// Stats: 147 math, 9 textures
Keywords { "POINT" }
Matrix 0 [_LightMatrix0] 3
Float 16 [_Bevel]
Float 19 [_BevelClamp]
Float 17 [_BevelOffset]
Float 20 [_BevelRoundness]
Float 18 [_BevelWidth]
Float 22 [_BumpFace]
Float 21 [_BumpOutline]
Vector 10 [_FaceColor]
Float 28 [_FaceShininess]
Float 8 [_FaceUVSpeedX]
Float 9 [_FaceUVSpeedY]
Float 27 [_GradientScale]
Vector 6 [_LightColor0]
Vector 14 [_OutlineColor]
Float 29 [_OutlineShininess]
Float 11 [_OutlineSoftness]
Float 12 [_OutlineUVSpeedX]
Float 13 [_OutlineUVSpeedY]
Float 15 [_OutlineWidth]
Float 24 [_ScaleRatioA]
Float 23 [_ShaderFlags]
Vector 7 [_SpecColor]
Float 26 [_TextureHeight]
Float 25 [_TextureWidth]
Vector 3 [_Time]
Vector 4 [_WorldSpaceCameraPos]
Vector 5 [_WorldSpaceLightPos0]
SetTexture 0 [_LightTexture0] 2D 0
SetTexture 1 [_FaceTex] 2D 1
SetTexture 2 [_OutlineTex] 2D 2
SetTexture 3 [_BumpMap] 2D 3
SetTexture 4 [_MainTex] 2D 4
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float _Bevel;
//   float _BevelClamp;
//   float _BevelOffset;
//   float _BevelRoundness;
//   float _BevelWidth;
//   float _BumpFace;
//   sampler2D _BumpMap;
//   float _BumpOutline;
//   float4 _FaceColor;
//   float _FaceShininess;
//   sampler2D _FaceTex;
//   float _FaceUVSpeedX;
//   float _FaceUVSpeedY;
//   float _GradientScale;
//   float4 _LightColor0;
//   row_major float4x4 _LightMatrix0;
//   sampler2D _LightTexture0;
//   sampler2D _MainTex;
//   float4 _OutlineColor;
//   float _OutlineShininess;
//   float _OutlineSoftness;
//   sampler2D _OutlineTex;
//   float _OutlineUVSpeedX;
//   float _OutlineUVSpeedY;
//   float _OutlineWidth;
//   float _ScaleRatioA;
//   float _ShaderFlags;
//   float4 _SpecColor;
//   float _TextureHeight;
//   float _TextureWidth;
//   float4 _Time;
//   float3 _WorldSpaceCameraPos;
//   float4 _WorldSpaceLightPos0;
//
//
// Registers:
//
//   Name                 Reg   Size
//   -------------------- ----- ----
//   _LightMatrix0        c0       3
//   _Time                c3       1
//   _WorldSpaceCameraPos c4       1
//   _WorldSpaceLightPos0 c5       1
//   _LightColor0         c6       1
//   _SpecColor           c7       1
//   _FaceUVSpeedX        c8       1
//   _FaceUVSpeedY        c9       1
//   _FaceColor           c10      1
//   _OutlineSoftness     c11      1
//   _OutlineUVSpeedX     c12      1
//   _OutlineUVSpeedY     c13      1
//   _OutlineColor        c14      1
//   _OutlineWidth        c15      1
//   _Bevel               c16      1
//   _BevelOffset         c17      1
//   _BevelWidth          c18      1
//   _BevelClamp          c19      1
//   _BevelRoundness      c20      1
//   _BumpOutline         c21      1
//   _BumpFace            c22      1
//   _ShaderFlags         c23      1
//   _ScaleRatioA         c24      1
//   _TextureWidth        c25      1
//   _TextureHeight       c26      1
//   _GradientScale       c27      1
//   _FaceShininess       c28      1
//   _OutlineShininess    c29      1
//   _LightTexture0       s0       1
//   _FaceTex             s1       1
//   _OutlineTex          s2       1
//   _BumpMap             s3       1
//   _MainTex             s4       1
//

    ps_3_0
    def c30, 10000, 0.00999999978, 2, -1
    def c31, 0.249999955, 0.25, 6.28318548, -3.14159274
    def c32, -2.52398507e-007, 2.47609005e-005, -0.00138883968, 0.0416666418
    def c33, 128, 0, 0, 0
    def c34, 0, 0.5, 1, -9.99999975e-005
    dcl_texcoord v0
    dcl_texcoord1_pp v1.xyz
    dcl_texcoord2_pp v2.xyz
    dcl_texcoord3_pp v3.xyz
    dcl_texcoord4 v4.xyz
    dcl_color_pp v5
    dcl_texcoord5 v6.xy
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    dcl_2d s3
    dcl_2d s4
    add r0.x, c17.x, v6.x
    rcp r1.x, c25.x
    rcp r1.w, c26.x
    mov r1.yz, c34.x
    add r2, -r1, v0.xyxy
    add r1, r1, v0.xyxy
    texld r3, r2, s4
    texld r2, r2.zwzw, s4
    mov r2.z, r2.w
    mov r2.x, r3.w
    texld r3, r1, s4
    texld r1, r1.zwzw, s4
    mov r2.w, r1.w
    mov r2.y, r3.w
    add r0, r0.x, r2
    mov r1.x, c15.x
    add r1.y, r1.x, c18.x
    max r2.x, c30.y, r1.y
    rcp r1.y, r2.x
    mul r1.z, r2.x, c16.x
    mul r1.z, r1.z, c27.x
    mul r1.z, r1.z, -c30.z
    lrp_sat r2, r1.y, r0, c34.y
    mad r0, r2, c30.z, c30.w
    add r0, -r0_abs, c34.z
    mov r3.yz, c34
    mul r1.y, r3.y, c23.x
    frc r1.y, r1_abs.y
    cmp r1.y, c23.x, r1.y, -r1.y
    add r1.y, r1.y, -c34.y
    cmp r0, r1.y, r0, r2
    mad r2, r0, c31.x, c31.y
    frc r2, r2
    mad r2, r2, c31.z, c31.w
    mul r2, r2, r2
    mad r4, r2, c32.x, c32.y
    mad r4, r2, r4, c32.z
    mad r4, r2, r4, c32.w
    mad r4, r2, r4, -c34.y
    mad r2, r2, r4, c34.z
    lrp r4, c20.x, r2, r0
    add r0.x, r3.z, -c19.x
    min r2, r0.x, r4
    mul r0.xy, r1.z, r2.xzzw
    mad r0.xy, r2.ywzw, r1.z, -r0
    mov r0.w, -c34.z
    dp2add r1.y, r0.wyzw, r0.wyzw, c34.x
    mul r2.xyz, r0.wyww, c34.zzxw
    rsq r0.y, r1.y
    mul r1.yzw, r0.y, r2.xxyz
    mov r0.z, c34.z
    dp2add r0.y, r0.zxzw, r0.zxzw, c34.x
    rsq r0.y, r0.y
    mul r2.x, r0.y, r0.x
    mul r2.yz, r0.y, c34.xzxw
    mul r0.xyz, r1.yzww, r2
    mad r0.xyz, r2.zxyw, r1.zwyw, -r0
    mov r1.y, c3.y
    mad r2.x, c12.x, r1.y, v0.z
    mad r2.y, c13.x, r1.y, v0.w
    texld r2, r2, s2
    mul_pp r2.xyz, r2, c14
    mul r0.w, c14.w, v5.w
    mul_pp r3.w, r2.w, r0.w
    mul_pp r3.xyz, r2, r3.w
    mad r2.x, c8.x, r1.y, v0.z
    mad r2.y, c9.x, r1.y, v0.w
    texld r2, r2, s1
    mul r4, c10, v5
    mul_pp r2, r2, r4
    mul_pp r2.xyz, r2.w, r2
    mul r0.w, r1.x, c24.x
    mad r1.x, r0.w, -v6.y, c34.z
    mul_pp r0.w, r0.w, v6.y
    rsq r1.y, r0.w
    rcp_pp r1.y, r1.y
    cmp_pp r1.x, r1.x, r1.y, c34.z
    texld r4, v0, s4
    add r1.y, -r4.w, c34.y
    add r1.y, r1.y, -v6.x
    mad_pp r1.y, r1.y, v6.y, c34.y
    mad_sat_pp r1.z, r0.w, c34.y, r1.y
    mad_pp r0.w, r0.w, -c34.y, r1.y
    mul_pp r1.x, r1.x, r1.z
    lrp_pp r4, r1.x, r3, r2
    mov r1.x, c24.x
    mul r1.x, r1.x, c11.x
    mul_pp r1.y, r1.x, v6.y
    mad_pp r1.x, r1.x, v6.y, c34.z
    rcp r1.x, r1.x
    mad_pp r0.w, r1.y, c34.y, r0.w
    mul_sat_pp r0.w, r1.x, r0.w
    add_pp r0.w, -r0.w, c34.z
    mul_pp r2, r0.w, r4
    mad r0.w, r4.w, r0.w, c34.w
    mov r1.x, c22.x
    add r1.x, -r1.x, c21.x
    mad r1.x, r1.z, r1.x, c22.x
    texld_pp r3, v0.zwzw, s3
    mad_pp r3.xy, r3.wyzw, c30.z, c30.w
    dp2add_sat_pp r1.y, r3, r3, c34.x
    add_pp r1.y, -r1.y, c34.z
    rsq_pp r1.y, r1.y
    rcp_pp r3.z, r1.y
    mad r1.xyw, r3.xyzz, r1.x, -c34.xxzz
    mad r1.xyw, r2.w, r1, c34.xxzz
    add r0.xyz, r0, -r1.xyww
    nrm_pp r3.xyz, r0
    dp3_pp r0.x, v1, -r3
    dp3_pp r0.y, v2, -r3
    dp3_pp r0.z, v3, -r3
    add r1.xyw, c4.xyzz, -v4.xyzz
    dp3 r3.x, r1.xyww, r1.xyww
    rsq r3.x, r3.x
    add r3.yzw, c5.xxyz, -v4.xxyz
    nrm_pp r4.xyz, r3.yzww
    mad_pp r1.xyw, r1, r3.x, r4.xyzz
    dp3_pp r3.x, r0, r4
    max_pp r4.x, r3.x, c34.x
    nrm_pp r3.xyz, r1.xyww
    dp3_pp r0.x, r0, r3
    max r1.x, r0.x, c34.x
    mov r0.x, c28.x
    add r0.x, -r0.x, c29.x
    mad_pp r0.x, r1.z, r0.x, c28.x
    mul r0.x, r0.x, c33.x
    pow r3.x, r1.x, r0.x
    mad r1, v4.xyzx, c34.zzzx, c34.xxxz
    dp4 r0.x, c0, r1
    dp4 r0.y, c1, r1
    dp4 r0.z, c2, r1
    dp3 r0.x, r0, r0
    texld_pp r1, r0.x, s0
    mul_pp r0.xyz, r1.x, c6
    mul r1.xyz, r0, c7
    mul r1.xyz, r3.x, r1
    rcp r1.w, r2.w
    cmp r0.w, r0.w, r1.w, c30.x
    mul_pp r2.xyz, r0.w, r2
    mov_pp oC0.w, r2.w
    mul_pp r0.xyz, r0, r2
    mad_pp oC0.xyz, r0, r4.x, r1

// approximately 153 instruction slots used (9 texture, 144 arithmetic)
"
}
SubProgram "d3d11 " {
// Stats: 112 math, 9 textures
Keywords { "POINT" }
SetTexture 0 [_MainTex] 2D 4
SetTexture 1 [_FaceTex] 2D 1
SetTexture 2 [_OutlineTex] 2D 2
SetTexture 3 [_BumpMap] 2D 3
SetTexture 4 [_LightTexture0] 2D 0
ConstBuffer "$Globals" 656
Matrix 128 [_LightMatrix0]
Vector 96 [_LightColor0]
Vector 112 [_SpecColor]
Float 192 [_FaceUVSpeedX]
Float 196 [_FaceUVSpeedY]
Vector 208 [_FaceColor]
Float 228 [_OutlineSoftness]
Float 232 [_OutlineUVSpeedX]
Float 236 [_OutlineUVSpeedY]
Vector 240 [_OutlineColor]
Float 256 [_OutlineWidth]
Float 260 [_Bevel]
Float 264 [_BevelOffset]
Float 268 [_BevelWidth]
Float 272 [_BevelClamp]
Float 276 [_BevelRoundness]
Float 280 [_BumpOutline]
Float 284 [_BumpFace]
Float 512 [_ShaderFlags]
Float 524 [_ScaleRatioA]
Float 584 [_TextureWidth]
Float 588 [_TextureHeight]
Float 592 [_GradientScale]
Float 608 [_FaceShininess]
Float 612 [_OutlineShininess]
ConstBuffer "UnityPerCamera" 144
Vector 0 [_Time]
Vector 64 [_WorldSpaceCameraPos] 3
ConstBuffer "UnityLighting" 720
Vector 0 [_WorldSpaceLightPos0]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityLighting" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
      ps_4_0
      dcl_constantbuffer cb0[39], immediateIndexed
      dcl_constantbuffer cb1[5], immediateIndexed
      dcl_constantbuffer cb2[1], immediateIndexed
      dcl_sampler s0, mode_default
      dcl_sampler s1, mode_default
      dcl_sampler s2, mode_default
      dcl_sampler s3, mode_default
      dcl_sampler s4, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_resource_texture2d (float,float,float,float) t1
      dcl_resource_texture2d (float,float,float,float) t2
      dcl_resource_texture2d (float,float,float,float) t3
      dcl_resource_texture2d (float,float,float,float) t4
      dcl_input_ps linear v1.xyzw
      dcl_input_ps linear v2.xyz
      dcl_input_ps linear v3.xyz
      dcl_input_ps linear v4.xyz
      dcl_input_ps linear v5.xyz
      dcl_input_ps linear v6.xyzw
      dcl_input_ps linear v7.xy
      dcl_output o0.xyzw
      dcl_temps 5
   0: add r0.x, v7.x, cb0[16].z
   1: div r1.xy, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[36].zwzz
   2: mov r1.z, l(0)
   3: add r2.xyzw, -r1.xzzy, v1.xyxy
   4: add r1.xyzw, r1.xzzy, v1.xyxy
   5: sample r3.xyzw, r2.xyxx, t0.wxyz, s4
   6: sample r2.xyzw, r2.zwzz, t0.xyzw, s4
   7: mov r3.z, r2.w
   8: sample r2.xyzw, r1.xyxx, t0.xyzw, s4
   9: sample r1.xyzw, r1.zwzz, t0.xyzw, s4
  10: mov r3.w, r1.w
  11: mov r3.y, r2.w
  12: add r0.xyzw, r0.xxxx, r3.xyzw
  13: add r0.xyzw, r0.xyzw, l(-0.500000, -0.500000, -0.500000, -0.500000)
  14: add r1.x, cb0[16].w, cb0[16].x
  15: max r1.x, r1.x, l(0.010000)
  16: div r0.xyzw, r0.xyzw, r1.xxxx
  17: mul r1.x, r1.x, cb0[16].y
  18: mul r1.x, r1.x, cb0[37].x
  19: mul r1.x, r1.x, l(-2.000000)
  20: add_sat r0.xyzw, r0.xyzw, l(0.500000, 0.500000, 0.500000, 0.500000)
  21: mad r2.xyzw, r0.xyzw, l(2.000000, 2.000000, 2.000000, 2.000000), l(-1.000000, -1.000000, -1.000000, -1.000000)
  22: add r2.xyzw, -|r2.xyzw|, l(1.000000, 1.000000, 1.000000, 1.000000)
  23: mul r1.y, cb0[32].x, l(0.500000)
  24: ge r1.z, r1.y, -r1.y
  25: frc r1.y, |r1.y|
  26: movc r1.y, r1.z, r1.y, -r1.y
  27: ge r1.y, r1.y, l(0.500000)
  28: movc r0.xyzw, r1.yyyy, r2.xyzw, r0.xyzw
  29: mul r2.xyzw, r0.xyzw, l(1.570796, 1.570796, 1.570796, 1.570796)
  30: sincos r2.xyzw, null, r2.xyzw
  31: add r2.xyzw, -r0.xyzw, r2.xyzw
  32: mad r0.xyzw, cb0[17].yyyy, r2.xyzw, r0.xyzw
  33: add r1.y, -cb0[17].x, l(1.000000)
  34: min r0.xyzw, r0.xyzw, r1.yyyy
  35: mul r0.xz, r1.xxxx, r0.xxzx
  36: mad r0.yz, r0.wwyw, r1.xxxx, -r0.zzxz
  37: mov r0.xw, l(-1.000000,0,0,1.000000)
  38: dp2 r1.x, r0.xyxx, r0.xyxx
  39: rsq r1.x, r1.x
  40: dp2 r0.w, r0.zwzz, r0.zwzz
  41: rsq r0.w, r0.w
  42: mul r2.x, r0.w, r0.z
  43: mul r2.yz, r0.wwww, l(0.000000, 1.000000, 0.000000, 0.000000)
  44: mov r0.z, l(0)
  45: mul r0.xyz, r1.xxxx, r0.xyzx
  46: mul r1.xyz, r0.xyzx, r2.xyzx
  47: mad r0.xyz, r2.zxyz, r0.yzxy, -r1.xyzx
  48: mad r1.xy, cb0[14].zwzz, cb1[0].yyyy, v1.zwzz
  49: sample r1.xyzw, r1.xyxx, t2.xyzw, s2
  50: mul r1.xyz, r1.xyzx, cb0[15].xyzx
  51: mul r0.w, v6.w, cb0[15].w
  52: mul r2.w, r1.w, r0.w
  53: mul r2.xyz, r1.xyzx, r2.wwww
  54: mad r1.xy, cb0[12].xyxx, cb1[0].yyyy, v1.zwzz
  55: sample r1.xyzw, r1.xyxx, t1.xyzw, s1
  56: mul r3.xyzw, v6.xyzw, cb0[13].xyzw
  57: mul r1.xyzw, r1.xyzw, r3.xyzw
  58: mul r1.xyz, r1.wwww, r1.xyzx
  59: add r2.xyzw, -r1.xyzw, r2.xyzw
  60: mul r0.w, cb0[16].x, cb0[32].w
  61: mul r0.w, r0.w, v7.y
  62: min r3.x, r0.w, l(1.000000)
  63: sqrt r3.x, r3.x
  64: sample r4.xyzw, v1.xyxx, t0.xyzw, s4
  65: add r3.y, -r4.w, l(0.500000)
  66: add r3.y, r3.y, -v7.x
  67: mad r3.y, r3.y, v7.y, l(0.500000)
  68: mad_sat r3.z, r0.w, l(0.500000), r3.y
  69: mad r0.w, -r0.w, l(0.500000), r3.y
  70: mul r3.x, r3.x, r3.z
  71: mad r1.xyzw, r3.xxxx, r2.xyzw, r1.xyzw
  72: mul r2.x, cb0[14].y, cb0[32].w
  73: mul r2.y, r2.x, v7.y
  74: mad r2.x, r2.x, v7.y, l(1.000000)
  75: mad r0.w, r2.y, l(0.500000), r0.w
  76: div_sat r0.w, r0.w, r2.x
  77: add r0.w, -r0.w, l(1.000000)
  78: mul r1.xyzw, r0.wwww, r1.xyzw
  79: add r0.w, -cb0[17].w, cb0[17].z
  80: mad r0.w, r3.z, r0.w, cb0[17].w
  81: sample r2.xyzw, v1.zwzz, t3.xyzw, s3
  82: mad r2.xy, r2.wyww, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
  83: dp2 r2.w, r2.xyxx, r2.xyxx
  84: min r2.w, r2.w, l(1.000000)
  85: add r2.w, -r2.w, l(1.000000)
  86: sqrt r2.z, r2.w
  87: mad r2.xyz, r2.xyzx, r0.wwww, l(-0.000000, -0.000000, -1.000000, 0.000000)
  88: mad r2.xyz, r1.wwww, r2.xyzx, l(0.000000, 0.000000, 1.000000, 0.000000)
  89: add r0.xyz, r0.xyzx, -r2.xyzx
  90: dp3 r0.w, r0.xyzx, r0.xyzx
  91: rsq r0.w, r0.w
  92: mul r0.xyz, r0.wwww, r0.xyzx
  93: dp3 r2.x, v2.xyzx, -r0.xyzx
  94: dp3 r2.y, v3.xyzx, -r0.xyzx
  95: dp3 r2.z, v4.xyzx, -r0.xyzx
  96: add r0.xyz, -v5.xyzx, cb2[0].xyzx
  97: dp3 r0.w, r0.xyzx, r0.xyzx
  98: rsq r0.w, r0.w
  99: mul r0.xyz, r0.wwww, r0.xyzx
 100: add r3.xyw, -v5.xyxz, cb1[4].xyxz
 101: dp3 r0.w, r3.xywx, r3.xywx
 102: rsq r0.w, r0.w
 103: mad r3.xyw, r3.xyxw, r0.wwww, r0.xyxz
 104: dp3 r0.x, r2.xyzx, r0.xyzx
 105: dp3 r0.y, r3.xywx, r3.xywx
 106: rsq r0.y, r0.y
 107: mul r0.yzw, r0.yyyy, r3.xxyw
 108: dp3 r0.y, r2.xyzx, r0.yzwy
 109: max r0.xy, r0.xyxx, l(0.000000, 0.000000, 0.000000, 0.000000)
 110: log r0.y, r0.y
 111: add r0.z, -cb0[38].x, cb0[38].y
 112: mad r0.z, r3.z, r0.z, cb0[38].x
 113: mul r0.z, r0.z, l(128.000000)
 114: mul r0.y, r0.y, r0.z
 115: exp r0.y, r0.y
 116: mul r2.xyz, v5.yyyy, cb0[9].xyzx
 117: mad r2.xyz, cb0[8].xyzx, v5.xxxx, r2.xyzx
 118: mad r2.xyz, cb0[10].xyzx, v5.zzzz, r2.xyzx
 119: add r2.xyz, r2.xyzx, cb0[11].xyzx
 120: dp3 r0.z, r2.xyzx, r2.xyzx
 121: sample r2.xyzw, r0.zzzz, t4.xyzw, s0
 122: mul r2.xyz, r2.xxxx, cb0[6].xyzx
 123: mul r3.xyz, r2.xyzx, cb0[7].xyzx
 124: mul r0.yzw, r0.yyyy, r3.xxyz
 125: max r2.w, r1.w, l(0.000100)
 126: div r1.xyz, r1.xyzx, r2.wwww
 127: mov o0.w, r1.w
 128: mul r1.xyz, r2.xyzx, r1.xyzx
 129: mad o0.xyz, r1.xyzx, r0.xxxx, r0.yzwy
 130: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
Keywords { "DIRECTIONAL" }
"// shader disassembly not supported on opengl"
}
SubProgram "d3d9 " {
// Stats: 137 math, 8 textures
Keywords { "DIRECTIONAL" }
Float 13 [_Bevel]
Float 16 [_BevelClamp]
Float 14 [_BevelOffset]
Float 17 [_BevelRoundness]
Float 15 [_BevelWidth]
Float 19 [_BumpFace]
Float 18 [_BumpOutline]
Vector 7 [_FaceColor]
Float 25 [_FaceShininess]
Float 5 [_FaceUVSpeedX]
Float 6 [_FaceUVSpeedY]
Float 24 [_GradientScale]
Vector 3 [_LightColor0]
Vector 11 [_OutlineColor]
Float 26 [_OutlineShininess]
Float 8 [_OutlineSoftness]
Float 9 [_OutlineUVSpeedX]
Float 10 [_OutlineUVSpeedY]
Float 12 [_OutlineWidth]
Float 21 [_ScaleRatioA]
Float 20 [_ShaderFlags]
Vector 4 [_SpecColor]
Float 23 [_TextureHeight]
Float 22 [_TextureWidth]
Vector 0 [_Time]
Vector 1 [_WorldSpaceCameraPos]
Vector 2 [_WorldSpaceLightPos0]
SetTexture 0 [_FaceTex] 2D 0
SetTexture 1 [_OutlineTex] 2D 1
SetTexture 2 [_BumpMap] 2D 2
SetTexture 3 [_MainTex] 2D 3
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float _Bevel;
//   float _BevelClamp;
//   float _BevelOffset;
//   float _BevelRoundness;
//   float _BevelWidth;
//   float _BumpFace;
//   sampler2D _BumpMap;
//   float _BumpOutline;
//   float4 _FaceColor;
//   float _FaceShininess;
//   sampler2D _FaceTex;
//   float _FaceUVSpeedX;
//   float _FaceUVSpeedY;
//   float _GradientScale;
//   float4 _LightColor0;
//   sampler2D _MainTex;
//   float4 _OutlineColor;
//   float _OutlineShininess;
//   float _OutlineSoftness;
//   sampler2D _OutlineTex;
//   float _OutlineUVSpeedX;
//   float _OutlineUVSpeedY;
//   float _OutlineWidth;
//   float _ScaleRatioA;
//   float _ShaderFlags;
//   float4 _SpecColor;
//   float _TextureHeight;
//   float _TextureWidth;
//   float4 _Time;
//   float3 _WorldSpaceCameraPos;
//   float4 _WorldSpaceLightPos0;
//
//
// Registers:
//
//   Name                 Reg   Size
//   -------------------- ----- ----
//   _Time                c0       1
//   _WorldSpaceCameraPos c1       1
//   _WorldSpaceLightPos0 c2       1
//   _LightColor0         c3       1
//   _SpecColor           c4       1
//   _FaceUVSpeedX        c5       1
//   _FaceUVSpeedY        c6       1
//   _FaceColor           c7       1
//   _OutlineSoftness     c8       1
//   _OutlineUVSpeedX     c9       1
//   _OutlineUVSpeedY     c10      1
//   _OutlineColor        c11      1
//   _OutlineWidth        c12      1
//   _Bevel               c13      1
//   _BevelOffset         c14      1
//   _BevelWidth          c15      1
//   _BevelClamp          c16      1
//   _BevelRoundness      c17      1
//   _BumpOutline         c18      1
//   _BumpFace            c19      1
//   _ShaderFlags         c20      1
//   _ScaleRatioA         c21      1
//   _TextureWidth        c22      1
//   _TextureHeight       c23      1
//   _GradientScale       c24      1
//   _FaceShininess       c25      1
//   _OutlineShininess    c26      1
//   _FaceTex             s0       1
//   _OutlineTex          s1       1
//   _BumpMap             s2       1
//   _MainTex             s3       1
//

    ps_3_0
    def c27, 10000, 0.00999999978, 2, -1
    def c28, 0.249999955, 0.25, 6.28318548, -3.14159274
    def c29, -2.52398507e-007, 2.47609005e-005, -0.00138883968, 0.0416666418
    def c30, 1, -1, 128, 0
    def c31, 0, 0.5, 1, -9.99999975e-005
    dcl_texcoord v0
    dcl_texcoord1_pp v1.xyz
    dcl_texcoord2_pp v2.xyz
    dcl_texcoord3_pp v3.xyz
    dcl_texcoord4 v4.xyz
    dcl_color_pp v5
    dcl_texcoord5 v6.xy
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    dcl_2d s3
    add r0.x, c14.x, v6.x
    rcp r1.x, c22.x
    rcp r1.w, c23.x
    mov r1.yz, c31.x
    add r2, -r1, v0.xyxy
    add r1, r1, v0.xyxy
    texld r3, r2, s3
    texld r2, r2.zwzw, s3
    mov r2.z, r2.w
    mov r2.x, r3.w
    texld r3, r1, s3
    texld r1, r1.zwzw, s3
    mov r2.w, r1.w
    mov r2.y, r3.w
    add r0, r0.x, r2
    mov r1.x, c12.x
    add r1.y, r1.x, c15.x
    max r2.x, c27.y, r1.y
    rcp r1.y, r2.x
    mul r1.z, r2.x, c13.x
    mul r1.z, r1.z, c24.x
    mul r1.z, r1.z, -c27.z
    lrp_sat r2, r1.y, r0, c31.y
    mad r0, r2, c27.z, c27.w
    add r0, -r0_abs, c31.z
    mov r3.yz, c31
    mul r1.y, r3.y, c20.x
    frc r1.y, r1_abs.y
    cmp r1.y, c20.x, r1.y, -r1.y
    add r1.y, r1.y, -c31.y
    cmp r0, r1.y, r0, r2
    mad r2, r0, c28.x, c28.y
    frc r2, r2
    mad r2, r2, c28.z, c28.w
    mul r2, r2, r2
    mad r4, r2, c29.x, c29.y
    mad r4, r2, r4, c29.z
    mad r4, r2, r4, c29.w
    mad r4, r2, r4, -c31.y
    mad r2, r2, r4, c31.z
    lrp r4, c17.x, r2, r0
    add r0.x, r3.z, -c16.x
    min r2, r0.x, r4
    mul r0.xy, r1.z, r2.xzzw
    mad r0.xy, r2.ywzw, r1.z, -r0
    mov r0.zw, c30.xyxy
    dp2add r1.y, r0.wyzw, r0.wyzw, c31.x
    rsq r1.y, r1.y
    mul r2.xyz, r0.wyww, c31.zzxw
    dp2add r0.y, r0.zxzw, r0.zxzw, c31.x
    rsq r0.y, r0.y
    mul r3.x, r0.y, r0.x
    mul r3.yz, r0.y, c31.xzxw
    mul r0.xyz, r1.y, r2
    mul r1.yzw, r0.xxyz, r3.xxyz
    mad r0.xyz, r3.zxyw, r0.yzxw, -r1.yzww
    mov r1.y, c0.y
    mad r2.x, c9.x, r1.y, v0.z
    mad r2.y, c10.x, r1.y, v0.w
    texld r2, r2, s1
    mul_pp r2.xyz, r2, c11
    mul r0.w, c11.w, v5.w
    mul_pp r3.w, r2.w, r0.w
    mul_pp r3.xyz, r2, r3.w
    mad r2.x, c5.x, r1.y, v0.z
    mad r2.y, c6.x, r1.y, v0.w
    texld r2, r2, s0
    mul r4, c7, v5
    mul_pp r2, r2, r4
    mul_pp r2.xyz, r2.w, r2
    mul r0.w, r1.x, c21.x
    mad r1.x, r0.w, -v6.y, c31.z
    mul_pp r0.w, r0.w, v6.y
    rsq r1.y, r0.w
    rcp_pp r1.y, r1.y
    cmp_pp r1.x, r1.x, r1.y, c31.z
    texld r4, v0, s3
    add r1.y, -r4.w, c31.y
    add r1.y, r1.y, -v6.x
    mad_pp r1.y, r1.y, v6.y, c31.y
    mad_sat_pp r1.z, r0.w, c31.y, r1.y
    mad_pp r0.w, r0.w, -c31.y, r1.y
    mul_pp r1.x, r1.x, r1.z
    lrp_pp r4, r1.x, r3, r2
    mov r1.x, c21.x
    mul r1.x, r1.x, c8.x
    mul_pp r1.y, r1.x, v6.y
    mad_pp r1.x, r1.x, v6.y, c31.z
    rcp r1.x, r1.x
    mad_pp r0.w, r1.y, c31.y, r0.w
    mul_sat_pp r0.w, r1.x, r0.w
    add_pp r0.w, -r0.w, c31.z
    mul_pp r2, r0.w, r4
    mad r0.w, r4.w, r0.w, c31.w
    mov r1.x, c19.x
    add r1.x, -r1.x, c18.x
    mad r1.x, r1.z, r1.x, c19.x
    texld_pp r3, v0.zwzw, s2
    mad_pp r3.xy, r3.wyzw, c27.z, c27.w
    dp2add_sat_pp r1.y, r3, r3, c31.x
    add_pp r1.y, -r1.y, c31.z
    rsq_pp r1.y, r1.y
    rcp_pp r3.z, r1.y
    mad r1.xyw, r3.xyzz, r1.x, -c31.xxzz
    mad r1.xyw, r2.w, r1, c31.xxzz
    add r0.xyz, r0, -r1.xyww
    nrm_pp r3.xyz, r0
    dp3_pp r0.x, v1, -r3
    dp3_pp r0.y, v2, -r3
    dp3_pp r0.z, v3, -r3
    add r1.xyw, c1.xyzz, -v4.xyzz
    dp3 r3.x, r1.xyww, r1.xyww
    rsq r3.x, r3.x
    mad_pp r1.xyw, r1, r3.x, c2.xyzz
    nrm_pp r3.xyz, r1.xyww
    dp3_pp r1.x, r0, r3
    dp3_pp r0.x, r0, c2
    max_pp r1.y, r0.x, c31.x
    max r0.x, r1.x, c31.x
    mov r1.x, c25.x
    add r0.y, -r1.x, c26.x
    mad_pp r0.y, r1.z, r0.y, c25.x
    mul r0.y, r0.y, c30.z
    pow r1.x, r0.x, r0.y
    mov r0.xyz, c3
    mul r0.xyz, r0, c4
    mul r0.xyz, r1.x, r0
    rcp r1.x, r2.w
    cmp r0.w, r0.w, r1.x, c27.x
    mul_pp r1.xzw, r0.w, r2.xyyz
    mov_pp oC0.w, r2.w
    mul_pp r1.xzw, r1, c3.xyyz
    mad_pp oC0.xyz, r1.xzww, r1.y, r0

// approximately 142 instruction slots used (8 texture, 134 arithmetic)
"
}
SubProgram "d3d11 " {
// Stats: 102 math, 8 textures
Keywords { "DIRECTIONAL" }
SetTexture 0 [_MainTex] 2D 3
SetTexture 1 [_FaceTex] 2D 0
SetTexture 2 [_OutlineTex] 2D 1
SetTexture 3 [_BumpMap] 2D 2
ConstBuffer "$Globals" 592
Vector 96 [_LightColor0]
Vector 112 [_SpecColor]
Float 128 [_FaceUVSpeedX]
Float 132 [_FaceUVSpeedY]
Vector 144 [_FaceColor]
Float 164 [_OutlineSoftness]
Float 168 [_OutlineUVSpeedX]
Float 172 [_OutlineUVSpeedY]
Vector 176 [_OutlineColor]
Float 192 [_OutlineWidth]
Float 196 [_Bevel]
Float 200 [_BevelOffset]
Float 204 [_BevelWidth]
Float 208 [_BevelClamp]
Float 212 [_BevelRoundness]
Float 216 [_BumpOutline]
Float 220 [_BumpFace]
Float 448 [_ShaderFlags]
Float 460 [_ScaleRatioA]
Float 520 [_TextureWidth]
Float 524 [_TextureHeight]
Float 528 [_GradientScale]
Float 544 [_FaceShininess]
Float 548 [_OutlineShininess]
ConstBuffer "UnityPerCamera" 144
Vector 0 [_Time]
Vector 64 [_WorldSpaceCameraPos] 3
ConstBuffer "UnityLighting" 720
Vector 0 [_WorldSpaceLightPos0]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityLighting" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
      ps_4_0
      dcl_constantbuffer cb0[35], immediateIndexed
      dcl_constantbuffer cb1[5], immediateIndexed
      dcl_constantbuffer cb2[1], immediateIndexed
      dcl_sampler s0, mode_default
      dcl_sampler s1, mode_default
      dcl_sampler s2, mode_default
      dcl_sampler s3, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_resource_texture2d (float,float,float,float) t1
      dcl_resource_texture2d (float,float,float,float) t2
      dcl_resource_texture2d (float,float,float,float) t3
      dcl_input_ps linear v1.xyzw
      dcl_input_ps linear v2.xyz
      dcl_input_ps linear v3.xyz
      dcl_input_ps linear v4.xyz
      dcl_input_ps linear v5.xyz
      dcl_input_ps linear v6.xyzw
      dcl_input_ps linear v7.xy
      dcl_output o0.xyzw
      dcl_temps 5
   0: add r0.x, v7.x, cb0[12].z
   1: div r1.xy, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[32].zwzz
   2: mov r1.z, l(0)
   3: add r2.xyzw, -r1.xzzy, v1.xyxy
   4: add r1.xyzw, r1.xzzy, v1.xyxy
   5: sample r3.xyzw, r2.xyxx, t0.wxyz, s3
   6: sample r2.xyzw, r2.zwzz, t0.xyzw, s3
   7: mov r3.z, r2.w
   8: sample r2.xyzw, r1.xyxx, t0.xyzw, s3
   9: sample r1.xyzw, r1.zwzz, t0.xyzw, s3
  10: mov r3.w, r1.w
  11: mov r3.y, r2.w
  12: add r0.xyzw, r0.xxxx, r3.xyzw
  13: add r0.xyzw, r0.xyzw, l(-0.500000, -0.500000, -0.500000, -0.500000)
  14: add r1.x, cb0[12].w, cb0[12].x
  15: max r1.x, r1.x, l(0.010000)
  16: div r0.xyzw, r0.xyzw, r1.xxxx
  17: mul r1.x, r1.x, cb0[12].y
  18: mul r1.x, r1.x, cb0[33].x
  19: mul r1.x, r1.x, l(-2.000000)
  20: add_sat r0.xyzw, r0.xyzw, l(0.500000, 0.500000, 0.500000, 0.500000)
  21: mad r2.xyzw, r0.xyzw, l(2.000000, 2.000000, 2.000000, 2.000000), l(-1.000000, -1.000000, -1.000000, -1.000000)
  22: add r2.xyzw, -|r2.xyzw|, l(1.000000, 1.000000, 1.000000, 1.000000)
  23: mul r1.y, cb0[28].x, l(0.500000)
  24: ge r1.z, r1.y, -r1.y
  25: frc r1.y, |r1.y|
  26: movc r1.y, r1.z, r1.y, -r1.y
  27: ge r1.y, r1.y, l(0.500000)
  28: movc r0.xyzw, r1.yyyy, r2.xyzw, r0.xyzw
  29: mul r2.xyzw, r0.xyzw, l(1.570796, 1.570796, 1.570796, 1.570796)
  30: sincos r2.xyzw, null, r2.xyzw
  31: add r2.xyzw, -r0.xyzw, r2.xyzw
  32: mad r0.xyzw, cb0[13].yyyy, r2.xyzw, r0.xyzw
  33: add r1.y, -cb0[13].x, l(1.000000)
  34: min r0.xyzw, r0.xyzw, r1.yyyy
  35: mul r0.xz, r1.xxxx, r0.xxzx
  36: mad r0.yz, r0.wwyw, r1.xxxx, -r0.zzxz
  37: mov r0.xw, l(-1.000000,0,0,1.000000)
  38: dp2 r1.x, r0.xyxx, r0.xyxx
  39: rsq r1.x, r1.x
  40: dp2 r0.w, r0.zwzz, r0.zwzz
  41: rsq r0.w, r0.w
  42: mul r2.x, r0.w, r0.z
  43: mul r2.yz, r0.wwww, l(0.000000, 1.000000, 0.000000, 0.000000)
  44: mov r0.z, l(0)
  45: mul r0.xyz, r1.xxxx, r0.xyzx
  46: mul r1.xyz, r0.xyzx, r2.xyzx
  47: mad r0.xyz, r2.zxyz, r0.yzxy, -r1.xyzx
  48: mad r1.xy, cb0[10].zwzz, cb1[0].yyyy, v1.zwzz
  49: sample r1.xyzw, r1.xyxx, t2.xyzw, s1
  50: mul r1.xyz, r1.xyzx, cb0[11].xyzx
  51: mul r0.w, v6.w, cb0[11].w
  52: mul r2.w, r1.w, r0.w
  53: mul r2.xyz, r1.xyzx, r2.wwww
  54: mad r1.xy, cb0[8].xyxx, cb1[0].yyyy, v1.zwzz
  55: sample r1.xyzw, r1.xyxx, t1.xyzw, s0
  56: mul r3.xyzw, v6.xyzw, cb0[9].xyzw
  57: mul r1.xyzw, r1.xyzw, r3.xyzw
  58: mul r1.xyz, r1.wwww, r1.xyzx
  59: add r2.xyzw, -r1.xyzw, r2.xyzw
  60: mul r0.w, cb0[12].x, cb0[28].w
  61: mul r0.w, r0.w, v7.y
  62: min r3.x, r0.w, l(1.000000)
  63: sqrt r3.x, r3.x
  64: sample r4.xyzw, v1.xyxx, t0.xyzw, s3
  65: add r3.y, -r4.w, l(0.500000)
  66: add r3.y, r3.y, -v7.x
  67: mad r3.y, r3.y, v7.y, l(0.500000)
  68: mad_sat r3.z, r0.w, l(0.500000), r3.y
  69: mad r0.w, -r0.w, l(0.500000), r3.y
  70: mul r3.x, r3.x, r3.z
  71: mad r1.xyzw, r3.xxxx, r2.xyzw, r1.xyzw
  72: mul r2.x, cb0[10].y, cb0[28].w
  73: mul r2.y, r2.x, v7.y
  74: mad r2.x, r2.x, v7.y, l(1.000000)
  75: mad r0.w, r2.y, l(0.500000), r0.w
  76: div_sat r0.w, r0.w, r2.x
  77: add r0.w, -r0.w, l(1.000000)
  78: mul r1.xyzw, r0.wwww, r1.xyzw
  79: add r0.w, -cb0[13].w, cb0[13].z
  80: mad r0.w, r3.z, r0.w, cb0[13].w
  81: sample r2.xyzw, v1.zwzz, t3.xyzw, s2
  82: mad r2.xy, r2.wyww, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
  83: dp2 r2.w, r2.xyxx, r2.xyxx
  84: min r2.w, r2.w, l(1.000000)
  85: add r2.w, -r2.w, l(1.000000)
  86: sqrt r2.z, r2.w
  87: mad r2.xyz, r2.xyzx, r0.wwww, l(-0.000000, -0.000000, -1.000000, 0.000000)
  88: mad r2.xyz, r1.wwww, r2.xyzx, l(0.000000, 0.000000, 1.000000, 0.000000)
  89: add r0.xyz, r0.xyzx, -r2.xyzx
  90: dp3 r0.w, r0.xyzx, r0.xyzx
  91: rsq r0.w, r0.w
  92: mul r0.xyz, r0.wwww, r0.xyzx
  93: dp3 r2.x, v2.xyzx, -r0.xyzx
  94: dp3 r2.y, v3.xyzx, -r0.xyzx
  95: dp3 r2.z, v4.xyzx, -r0.xyzx
  96: add r0.xyz, -v5.xyzx, cb1[4].xyzx
  97: dp3 r0.w, r0.xyzx, r0.xyzx
  98: rsq r0.w, r0.w
  99: mad r0.xyz, r0.xyzx, r0.wwww, cb2[0].xyzx
 100: dp3 r0.w, r0.xyzx, r0.xyzx
 101: rsq r0.w, r0.w
 102: mul r0.xyz, r0.wwww, r0.xyzx
 103: dp3 r0.x, r2.xyzx, r0.xyzx
 104: dp3 r0.y, r2.xyzx, cb2[0].xyzx
 105: max r0.xy, r0.xyxx, l(0.000000, 0.000000, 0.000000, 0.000000)
 106: log r0.x, r0.x
 107: add r0.z, -cb0[34].x, cb0[34].y
 108: mad r0.z, r3.z, r0.z, cb0[34].x
 109: mul r0.z, r0.z, l(128.000000)
 110: mul r0.x, r0.x, r0.z
 111: exp r0.x, r0.x
 112: mul r2.xyz, cb0[6].xyzx, cb0[7].xyzx
 113: mul r0.xzw, r0.xxxx, r2.xxyz
 114: max r2.x, r1.w, l(0.000100)
 115: div r1.xyz, r1.xyzx, r2.xxxx
 116: mov o0.w, r1.w
 117: mul r1.xyz, r1.xyzx, cb0[6].xyzx
 118: mad o0.xyz, r1.xyzx, r0.yyyy, r0.xzwx
 119: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
Keywords { "SPOT" }
"// shader disassembly not supported on opengl"
}
SubProgram "d3d9 " {
// Stats: 152 math, 10 textures
Keywords { "SPOT" }
Matrix 0 [_LightMatrix0]
Float 17 [_Bevel]
Float 20 [_BevelClamp]
Float 18 [_BevelOffset]
Float 21 [_BevelRoundness]
Float 19 [_BevelWidth]
Float 23 [_BumpFace]
Float 22 [_BumpOutline]
Vector 11 [_FaceColor]
Float 29 [_FaceShininess]
Float 9 [_FaceUVSpeedX]
Float 10 [_FaceUVSpeedY]
Float 28 [_GradientScale]
Vector 7 [_LightColor0]
Vector 15 [_OutlineColor]
Float 30 [_OutlineShininess]
Float 12 [_OutlineSoftness]
Float 13 [_OutlineUVSpeedX]
Float 14 [_OutlineUVSpeedY]
Float 16 [_OutlineWidth]
Float 25 [_ScaleRatioA]
Float 24 [_ShaderFlags]
Vector 8 [_SpecColor]
Float 27 [_TextureHeight]
Float 26 [_TextureWidth]
Vector 4 [_Time]
Vector 5 [_WorldSpaceCameraPos]
Vector 6 [_WorldSpaceLightPos0]
SetTexture 0 [_LightTexture0] 2D 0
SetTexture 1 [_LightTextureB0] 2D 1
SetTexture 2 [_FaceTex] 2D 2
SetTexture 3 [_OutlineTex] 2D 3
SetTexture 4 [_BumpMap] 2D 4
SetTexture 5 [_MainTex] 2D 5
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float _Bevel;
//   float _BevelClamp;
//   float _BevelOffset;
//   float _BevelRoundness;
//   float _BevelWidth;
//   float _BumpFace;
//   sampler2D _BumpMap;
//   float _BumpOutline;
//   float4 _FaceColor;
//   float _FaceShininess;
//   sampler2D _FaceTex;
//   float _FaceUVSpeedX;
//   float _FaceUVSpeedY;
//   float _GradientScale;
//   float4 _LightColor0;
//   row_major float4x4 _LightMatrix0;
//   sampler2D _LightTexture0;
//   sampler2D _LightTextureB0;
//   sampler2D _MainTex;
//   float4 _OutlineColor;
//   float _OutlineShininess;
//   float _OutlineSoftness;
//   sampler2D _OutlineTex;
//   float _OutlineUVSpeedX;
//   float _OutlineUVSpeedY;
//   float _OutlineWidth;
//   float _ScaleRatioA;
//   float _ShaderFlags;
//   float4 _SpecColor;
//   float _TextureHeight;
//   float _TextureWidth;
//   float4 _Time;
//   float3 _WorldSpaceCameraPos;
//   float4 _WorldSpaceLightPos0;
//
//
// Registers:
//
//   Name                 Reg   Size
//   -------------------- ----- ----
//   _LightMatrix0        c0       4
//   _Time                c4       1
//   _WorldSpaceCameraPos c5       1
//   _WorldSpaceLightPos0 c6       1
//   _LightColor0         c7       1
//   _SpecColor           c8       1
//   _FaceUVSpeedX        c9       1
//   _FaceUVSpeedY        c10      1
//   _FaceColor           c11      1
//   _OutlineSoftness     c12      1
//   _OutlineUVSpeedX     c13      1
//   _OutlineUVSpeedY     c14      1
//   _OutlineColor        c15      1
//   _OutlineWidth        c16      1
//   _Bevel               c17      1
//   _BevelOffset         c18      1
//   _BevelWidth          c19      1
//   _BevelClamp          c20      1
//   _BevelRoundness      c21      1
//   _BumpOutline         c22      1
//   _BumpFace            c23      1
//   _ShaderFlags         c24      1
//   _ScaleRatioA         c25      1
//   _TextureWidth        c26      1
//   _TextureHeight       c27      1
//   _GradientScale       c28      1
//   _FaceShininess       c29      1
//   _OutlineShininess    c30      1
//   _LightTexture0       s0       1
//   _LightTextureB0      s1       1
//   _FaceTex             s2       1
//   _OutlineTex          s3       1
//   _BumpMap             s4       1
//   _MainTex             s5       1
//

    ps_3_0
    def c31, 10000, 0.00999999978, 2, -1
    def c32, 0.249999955, 0.25, 6.28318548, -3.14159274
    def c33, -2.52398507e-007, 2.47609005e-005, -0.00138883968, 0.0416666418
    def c34, 128, 0, 0, 0
    def c35, 0, 0.5, 1, -9.99999975e-005
    dcl_texcoord v0
    dcl_texcoord1_pp v1.xyz
    dcl_texcoord2_pp v2.xyz
    dcl_texcoord3_pp v3.xyz
    dcl_texcoord4 v4.xyz
    dcl_color_pp v5
    dcl_texcoord5 v6.xy
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    dcl_2d s3
    dcl_2d s4
    dcl_2d s5
    add r0.x, c18.x, v6.x
    rcp r1.x, c26.x
    rcp r1.w, c27.x
    mov r1.yz, c35.x
    add r2, -r1, v0.xyxy
    add r1, r1, v0.xyxy
    texld r3, r2, s5
    texld r2, r2.zwzw, s5
    mov r2.z, r2.w
    mov r2.x, r3.w
    texld r3, r1, s5
    texld r1, r1.zwzw, s5
    mov r2.w, r1.w
    mov r2.y, r3.w
    add r0, r0.x, r2
    mov r1.x, c16.x
    add r1.y, r1.x, c19.x
    max r2.x, c31.y, r1.y
    rcp r1.y, r2.x
    mul r1.z, r2.x, c17.x
    mul r1.z, r1.z, c28.x
    mul r1.z, r1.z, -c31.z
    lrp_sat r2, r1.y, r0, c35.y
    mad r0, r2, c31.z, c31.w
    add r0, -r0_abs, c35.z
    mov r3.yz, c35
    mul r1.y, r3.y, c24.x
    frc r1.y, r1_abs.y
    cmp r1.y, c24.x, r1.y, -r1.y
    add r1.y, r1.y, -c35.y
    cmp r0, r1.y, r0, r2
    mad r2, r0, c32.x, c32.y
    frc r2, r2
    mad r2, r2, c32.z, c32.w
    mul r2, r2, r2
    mad r4, r2, c33.x, c33.y
    mad r4, r2, r4, c33.z
    mad r4, r2, r4, c33.w
    mad r4, r2, r4, -c35.y
    mad r2, r2, r4, c35.z
    lrp r4, c21.x, r2, r0
    add r0.x, r3.z, -c20.x
    min r2, r0.x, r4
    mul r0.xy, r1.z, r2.xzzw
    mad r0.xy, r2.ywzw, r1.z, -r0
    mov r0.w, -c35.z
    dp2add r1.y, r0.wyzw, r0.wyzw, c35.x
    mul r2.xyz, r0.wyww, c35.zzxw
    rsq r0.y, r1.y
    mul r1.yzw, r0.y, r2.xxyz
    mov r0.z, c35.z
    dp2add r0.y, r0.zxzw, r0.zxzw, c35.x
    rsq r0.y, r0.y
    mul r2.x, r0.y, r0.x
    mul r2.yz, r0.y, c35.xzxw
    mul r0.xyz, r1.yzww, r2
    mad r0.xyz, r2.zxyw, r1.zwyw, -r0
    mov r1.y, c4.y
    mad r2.x, c13.x, r1.y, v0.z
    mad r2.y, c14.x, r1.y, v0.w
    texld r2, r2, s3
    mul_pp r2.xyz, r2, c15
    mul r0.w, c15.w, v5.w
    mul_pp r3.w, r2.w, r0.w
    mul_pp r3.xyz, r2, r3.w
    mad r2.x, c9.x, r1.y, v0.z
    mad r2.y, c10.x, r1.y, v0.w
    texld r2, r2, s2
    mul r4, c11, v5
    mul_pp r2, r2, r4
    mul_pp r2.xyz, r2.w, r2
    mul r0.w, r1.x, c25.x
    mad r1.x, r0.w, -v6.y, c35.z
    mul_pp r0.w, r0.w, v6.y
    rsq r1.y, r0.w
    rcp_pp r1.y, r1.y
    cmp_pp r1.x, r1.x, r1.y, c35.z
    texld r4, v0, s5
    add r1.y, -r4.w, c35.y
    add r1.y, r1.y, -v6.x
    mad_pp r1.y, r1.y, v6.y, c35.y
    mad_sat_pp r1.z, r0.w, c35.y, r1.y
    mad_pp r0.w, r0.w, -c35.y, r1.y
    mul_pp r1.x, r1.x, r1.z
    lrp_pp r4, r1.x, r3, r2
    mov r1.x, c25.x
    mul r1.x, r1.x, c12.x
    mul_pp r1.y, r1.x, v6.y
    mad_pp r1.x, r1.x, v6.y, c35.z
    rcp r1.x, r1.x
    mad_pp r0.w, r1.y, c35.y, r0.w
    mul_sat_pp r0.w, r1.x, r0.w
    add_pp r0.w, -r0.w, c35.z
    mul_pp r2, r0.w, r4
    mad r0.w, r4.w, r0.w, c35.w
    mov r1.x, c23.x
    add r1.x, -r1.x, c22.x
    mad r1.x, r1.z, r1.x, c23.x
    texld_pp r3, v0.zwzw, s4
    mad_pp r3.xy, r3.wyzw, c31.z, c31.w
    dp2add_sat_pp r1.y, r3, r3, c35.x
    add_pp r1.y, -r1.y, c35.z
    rsq_pp r1.y, r1.y
    rcp_pp r3.z, r1.y
    mad r1.xyw, r3.xyzz, r1.x, -c35.xxzz
    mad r1.xyw, r2.w, r1, c35.xxzz
    add r0.xyz, r0, -r1.xyww
    nrm_pp r3.xyz, r0
    dp3_pp r0.x, v1, -r3
    dp3_pp r0.y, v2, -r3
    dp3_pp r0.z, v3, -r3
    add r1.xyw, c5.xyzz, -v4.xyzz
    dp3 r3.x, r1.xyww, r1.xyww
    rsq r3.x, r3.x
    add r3.yzw, c6.xxyz, -v4.xxyz
    nrm_pp r4.xyz, r3.yzww
    mad_pp r1.xyw, r1, r3.x, r4.xyzz
    dp3_pp r3.x, r0, r4
    max_pp r4.x, r3.x, c35.x
    nrm_pp r3.xyz, r1.xyww
    dp3_pp r0.x, r0, r3
    max r1.x, r0.x, c35.x
    mov r0.x, c29.x
    add r0.x, -r0.x, c30.x
    mad_pp r0.x, r1.z, r0.x, c29.x
    mul r0.x, r0.x, c34.x
    pow r3.x, r1.x, r0.x
    mad r1, v4.xyzx, c35.zzzx, c35.xxxz
    dp4 r0.x, c3, r1
    rcp r0.x, r0.x
    dp4 r5.x, c0, r1
    dp4 r5.y, c1, r1
    dp4 r5.z, c2, r1
    mad r0.xy, r5, r0.x, c35.y
    dp3 r0.z, r5, r5
    texld_pp r1, r0.z, s1
    texld_pp r6, r0, s0
    mul r0.x, r1.x, r6.w
    mul_pp r0.xyz, r0.x, c7
    cmp_pp r0.xyz, -r5.z, c35.x, r0
    mul r1.xyz, r0, c8
    mul r1.xyz, r3.x, r1
    rcp r1.w, r2.w
    cmp r0.w, r0.w, r1.w, c31.x
    mul_pp r2.xyz, r0.w, r2
    mov_pp oC0.w, r2.w
    mul_pp r0.xyz, r0, r2
    mad_pp oC0.xyz, r0, r4.x, r1

// approximately 159 instruction slots used (10 texture, 149 arithmetic)
"
}
SubProgram "d3d11 " {
// Stats: 118 math, 10 textures
Keywords { "SPOT" }
SetTexture 0 [_MainTex] 2D 5
SetTexture 1 [_FaceTex] 2D 2
SetTexture 2 [_OutlineTex] 2D 3
SetTexture 3 [_BumpMap] 2D 4
SetTexture 4 [_LightTexture0] 2D 0
SetTexture 5 [_LightTextureB0] 2D 1
ConstBuffer "$Globals" 656
Matrix 128 [_LightMatrix0]
Vector 96 [_LightColor0]
Vector 112 [_SpecColor]
Float 192 [_FaceUVSpeedX]
Float 196 [_FaceUVSpeedY]
Vector 208 [_FaceColor]
Float 228 [_OutlineSoftness]
Float 232 [_OutlineUVSpeedX]
Float 236 [_OutlineUVSpeedY]
Vector 240 [_OutlineColor]
Float 256 [_OutlineWidth]
Float 260 [_Bevel]
Float 264 [_BevelOffset]
Float 268 [_BevelWidth]
Float 272 [_BevelClamp]
Float 276 [_BevelRoundness]
Float 280 [_BumpOutline]
Float 284 [_BumpFace]
Float 512 [_ShaderFlags]
Float 524 [_ScaleRatioA]
Float 584 [_TextureWidth]
Float 588 [_TextureHeight]
Float 592 [_GradientScale]
Float 608 [_FaceShininess]
Float 612 [_OutlineShininess]
ConstBuffer "UnityPerCamera" 144
Vector 0 [_Time]
Vector 64 [_WorldSpaceCameraPos] 3
ConstBuffer "UnityLighting" 720
Vector 0 [_WorldSpaceLightPos0]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityLighting" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
      ps_4_0
      dcl_constantbuffer cb0[39], immediateIndexed
      dcl_constantbuffer cb1[5], immediateIndexed
      dcl_constantbuffer cb2[1], immediateIndexed
      dcl_sampler s0, mode_default
      dcl_sampler s1, mode_default
      dcl_sampler s2, mode_default
      dcl_sampler s3, mode_default
      dcl_sampler s4, mode_default
      dcl_sampler s5, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_resource_texture2d (float,float,float,float) t1
      dcl_resource_texture2d (float,float,float,float) t2
      dcl_resource_texture2d (float,float,float,float) t3
      dcl_resource_texture2d (float,float,float,float) t4
      dcl_resource_texture2d (float,float,float,float) t5
      dcl_input_ps linear v1.xyzw
      dcl_input_ps linear v2.xyz
      dcl_input_ps linear v3.xyz
      dcl_input_ps linear v4.xyz
      dcl_input_ps linear v5.xyz
      dcl_input_ps linear v6.xyzw
      dcl_input_ps linear v7.xy
      dcl_output o0.xyzw
      dcl_temps 5
   0: add r0.x, v7.x, cb0[16].z
   1: div r1.xy, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[36].zwzz
   2: mov r1.z, l(0)
   3: add r2.xyzw, -r1.xzzy, v1.xyxy
   4: add r1.xyzw, r1.xzzy, v1.xyxy
   5: sample r3.xyzw, r2.xyxx, t0.wxyz, s5
   6: sample r2.xyzw, r2.zwzz, t0.xyzw, s5
   7: mov r3.z, r2.w
   8: sample r2.xyzw, r1.xyxx, t0.xyzw, s5
   9: sample r1.xyzw, r1.zwzz, t0.xyzw, s5
  10: mov r3.w, r1.w
  11: mov r3.y, r2.w
  12: add r0.xyzw, r0.xxxx, r3.xyzw
  13: add r0.xyzw, r0.xyzw, l(-0.500000, -0.500000, -0.500000, -0.500000)
  14: add r1.x, cb0[16].w, cb0[16].x
  15: max r1.x, r1.x, l(0.010000)
  16: div r0.xyzw, r0.xyzw, r1.xxxx
  17: mul r1.x, r1.x, cb0[16].y
  18: mul r1.x, r1.x, cb0[37].x
  19: mul r1.x, r1.x, l(-2.000000)
  20: add_sat r0.xyzw, r0.xyzw, l(0.500000, 0.500000, 0.500000, 0.500000)
  21: mad r2.xyzw, r0.xyzw, l(2.000000, 2.000000, 2.000000, 2.000000), l(-1.000000, -1.000000, -1.000000, -1.000000)
  22: add r2.xyzw, -|r2.xyzw|, l(1.000000, 1.000000, 1.000000, 1.000000)
  23: mul r1.y, cb0[32].x, l(0.500000)
  24: ge r1.z, r1.y, -r1.y
  25: frc r1.y, |r1.y|
  26: movc r1.y, r1.z, r1.y, -r1.y
  27: ge r1.y, r1.y, l(0.500000)
  28: movc r0.xyzw, r1.yyyy, r2.xyzw, r0.xyzw
  29: mul r2.xyzw, r0.xyzw, l(1.570796, 1.570796, 1.570796, 1.570796)
  30: sincos r2.xyzw, null, r2.xyzw
  31: add r2.xyzw, -r0.xyzw, r2.xyzw
  32: mad r0.xyzw, cb0[17].yyyy, r2.xyzw, r0.xyzw
  33: add r1.y, -cb0[17].x, l(1.000000)
  34: min r0.xyzw, r0.xyzw, r1.yyyy
  35: mul r0.xz, r1.xxxx, r0.xxzx
  36: mad r0.yz, r0.wwyw, r1.xxxx, -r0.zzxz
  37: mov r0.xw, l(-1.000000,0,0,1.000000)
  38: dp2 r1.x, r0.xyxx, r0.xyxx
  39: rsq r1.x, r1.x
  40: dp2 r0.w, r0.zwzz, r0.zwzz
  41: rsq r0.w, r0.w
  42: mul r2.x, r0.w, r0.z
  43: mul r2.yz, r0.wwww, l(0.000000, 1.000000, 0.000000, 0.000000)
  44: mov r0.z, l(0)
  45: mul r0.xyz, r1.xxxx, r0.xyzx
  46: mul r1.xyz, r0.xyzx, r2.xyzx
  47: mad r0.xyz, r2.zxyz, r0.yzxy, -r1.xyzx
  48: mad r1.xy, cb0[14].zwzz, cb1[0].yyyy, v1.zwzz
  49: sample r1.xyzw, r1.xyxx, t2.xyzw, s3
  50: mul r1.xyz, r1.xyzx, cb0[15].xyzx
  51: mul r0.w, v6.w, cb0[15].w
  52: mul r2.w, r1.w, r0.w
  53: mul r2.xyz, r1.xyzx, r2.wwww
  54: mad r1.xy, cb0[12].xyxx, cb1[0].yyyy, v1.zwzz
  55: sample r1.xyzw, r1.xyxx, t1.xyzw, s2
  56: mul r3.xyzw, v6.xyzw, cb0[13].xyzw
  57: mul r1.xyzw, r1.xyzw, r3.xyzw
  58: mul r1.xyz, r1.wwww, r1.xyzx
  59: add r2.xyzw, -r1.xyzw, r2.xyzw
  60: mul r0.w, cb0[16].x, cb0[32].w
  61: mul r0.w, r0.w, v7.y
  62: min r3.x, r0.w, l(1.000000)
  63: sqrt r3.x, r3.x
  64: sample r4.xyzw, v1.xyxx, t0.xyzw, s5
  65: add r3.y, -r4.w, l(0.500000)
  66: add r3.y, r3.y, -v7.x
  67: mad r3.y, r3.y, v7.y, l(0.500000)
  68: mad_sat r3.z, r0.w, l(0.500000), r3.y
  69: mad r0.w, -r0.w, l(0.500000), r3.y
  70: mul r3.x, r3.x, r3.z
  71: mad r1.xyzw, r3.xxxx, r2.xyzw, r1.xyzw
  72: mul r2.x, cb0[14].y, cb0[32].w
  73: mul r2.y, r2.x, v7.y
  74: mad r2.x, r2.x, v7.y, l(1.000000)
  75: mad r0.w, r2.y, l(0.500000), r0.w
  76: div_sat r0.w, r0.w, r2.x
  77: add r0.w, -r0.w, l(1.000000)
  78: mul r1.xyzw, r0.wwww, r1.xyzw
  79: add r0.w, -cb0[17].w, cb0[17].z
  80: mad r0.w, r3.z, r0.w, cb0[17].w
  81: sample r2.xyzw, v1.zwzz, t3.xyzw, s4
  82: mad r2.xy, r2.wyww, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
  83: dp2 r2.w, r2.xyxx, r2.xyxx
  84: min r2.w, r2.w, l(1.000000)
  85: add r2.w, -r2.w, l(1.000000)
  86: sqrt r2.z, r2.w
  87: mad r2.xyz, r2.xyzx, r0.wwww, l(-0.000000, -0.000000, -1.000000, 0.000000)
  88: mad r2.xyz, r1.wwww, r2.xyzx, l(0.000000, 0.000000, 1.000000, 0.000000)
  89: add r0.xyz, r0.xyzx, -r2.xyzx
  90: dp3 r0.w, r0.xyzx, r0.xyzx
  91: rsq r0.w, r0.w
  92: mul r0.xyz, r0.wwww, r0.xyzx
  93: dp3 r2.x, v2.xyzx, -r0.xyzx
  94: dp3 r2.y, v3.xyzx, -r0.xyzx
  95: dp3 r2.z, v4.xyzx, -r0.xyzx
  96: add r0.xyz, -v5.xyzx, cb2[0].xyzx
  97: dp3 r0.w, r0.xyzx, r0.xyzx
  98: rsq r0.w, r0.w
  99: mul r0.xyz, r0.wwww, r0.xyzx
 100: add r3.xyw, -v5.xyxz, cb1[4].xyxz
 101: dp3 r0.w, r3.xywx, r3.xywx
 102: rsq r0.w, r0.w
 103: mad r3.xyw, r3.xyxw, r0.wwww, r0.xyxz
 104: dp3 r0.x, r2.xyzx, r0.xyzx
 105: dp3 r0.y, r3.xywx, r3.xywx
 106: rsq r0.y, r0.y
 107: mul r0.yzw, r0.yyyy, r3.xxyw
 108: dp3 r0.y, r2.xyzx, r0.yzwy
 109: max r0.xy, r0.xyxx, l(0.000000, 0.000000, 0.000000, 0.000000)
 110: log r0.y, r0.y
 111: add r0.z, -cb0[38].x, cb0[38].y
 112: mad r0.z, r3.z, r0.z, cb0[38].x
 113: mul r0.z, r0.z, l(128.000000)
 114: mul r0.y, r0.y, r0.z
 115: exp r0.y, r0.y
 116: mul r2.xyzw, v5.yyyy, cb0[9].xyzw
 117: mad r2.xyzw, cb0[8].xyzw, v5.xxxx, r2.xyzw
 118: mad r2.xyzw, cb0[10].xyzw, v5.zzzz, r2.xyzw
 119: add r2.xyzw, r2.xyzw, cb0[11].xyzw
 120: div r0.zw, r2.xxxy, r2.wwww
 121: add r0.zw, r0.zzzw, l(0.000000, 0.000000, 0.500000, 0.500000)
 122: sample r3.xyzw, r0.zwzz, t4.xyzw, s0
 123: lt r0.z, l(0.000000), r2.z
 124: dp3 r0.w, r2.xyzx, r2.xyzx
 125: sample r2.xyzw, r0.wwww, t5.xyzw, s1
 126: and r0.z, r0.z, l(0x3f800000)
 127: mul r0.z, r3.w, r0.z
 128: mul r0.z, r2.x, r0.z
 129: mul r2.xyz, r0.zzzz, cb0[6].xyzx
 130: mul r3.xyz, r2.xyzx, cb0[7].xyzx
 131: mul r0.yzw, r0.yyyy, r3.xxyz
 132: max r2.w, r1.w, l(0.000100)
 133: div r1.xyz, r1.xyzx, r2.wwww
 134: mov o0.w, r1.w
 135: mul r1.xyz, r2.xyzx, r1.xyzx
 136: mad o0.xyz, r1.xyzx, r0.xxxx, r0.yzwy
 137: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
Keywords { "POINT_COOKIE" }
"// shader disassembly not supported on opengl"
}
SubProgram "d3d9 " {
// Stats: 148 math, 10 textures
Keywords { "POINT_COOKIE" }
Matrix 0 [_LightMatrix0] 3
Float 16 [_Bevel]
Float 19 [_BevelClamp]
Float 17 [_BevelOffset]
Float 20 [_BevelRoundness]
Float 18 [_BevelWidth]
Float 22 [_BumpFace]
Float 21 [_BumpOutline]
Vector 10 [_FaceColor]
Float 28 [_FaceShininess]
Float 8 [_FaceUVSpeedX]
Float 9 [_FaceUVSpeedY]
Float 27 [_GradientScale]
Vector 6 [_LightColor0]
Vector 14 [_OutlineColor]
Float 29 [_OutlineShininess]
Float 11 [_OutlineSoftness]
Float 12 [_OutlineUVSpeedX]
Float 13 [_OutlineUVSpeedY]
Float 15 [_OutlineWidth]
Float 24 [_ScaleRatioA]
Float 23 [_ShaderFlags]
Vector 7 [_SpecColor]
Float 26 [_TextureHeight]
Float 25 [_TextureWidth]
Vector 3 [_Time]
Vector 4 [_WorldSpaceCameraPos]
Vector 5 [_WorldSpaceLightPos0]
SetTexture 0 [_LightTexture0] CUBE 0
SetTexture 1 [_LightTextureB0] 2D 1
SetTexture 2 [_FaceTex] 2D 2
SetTexture 3 [_OutlineTex] 2D 3
SetTexture 4 [_BumpMap] 2D 4
SetTexture 5 [_MainTex] 2D 5
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float _Bevel;
//   float _BevelClamp;
//   float _BevelOffset;
//   float _BevelRoundness;
//   float _BevelWidth;
//   float _BumpFace;
//   sampler2D _BumpMap;
//   float _BumpOutline;
//   float4 _FaceColor;
//   float _FaceShininess;
//   sampler2D _FaceTex;
//   float _FaceUVSpeedX;
//   float _FaceUVSpeedY;
//   float _GradientScale;
//   float4 _LightColor0;
//   row_major float4x4 _LightMatrix0;
//   samplerCUBE _LightTexture0;
//   sampler2D _LightTextureB0;
//   sampler2D _MainTex;
//   float4 _OutlineColor;
//   float _OutlineShininess;
//   float _OutlineSoftness;
//   sampler2D _OutlineTex;
//   float _OutlineUVSpeedX;
//   float _OutlineUVSpeedY;
//   float _OutlineWidth;
//   float _ScaleRatioA;
//   float _ShaderFlags;
//   float4 _SpecColor;
//   float _TextureHeight;
//   float _TextureWidth;
//   float4 _Time;
//   float3 _WorldSpaceCameraPos;
//   float4 _WorldSpaceLightPos0;
//
//
// Registers:
//
//   Name                 Reg   Size
//   -------------------- ----- ----
//   _LightMatrix0        c0       3
//   _Time                c3       1
//   _WorldSpaceCameraPos c4       1
//   _WorldSpaceLightPos0 c5       1
//   _LightColor0         c6       1
//   _SpecColor           c7       1
//   _FaceUVSpeedX        c8       1
//   _FaceUVSpeedY        c9       1
//   _FaceColor           c10      1
//   _OutlineSoftness     c11      1
//   _OutlineUVSpeedX     c12      1
//   _OutlineUVSpeedY     c13      1
//   _OutlineColor        c14      1
//   _OutlineWidth        c15      1
//   _Bevel               c16      1
//   _BevelOffset         c17      1
//   _BevelWidth          c18      1
//   _BevelClamp          c19      1
//   _BevelRoundness      c20      1
//   _BumpOutline         c21      1
//   _BumpFace            c22      1
//   _ShaderFlags         c23      1
//   _ScaleRatioA         c24      1
//   _TextureWidth        c25      1
//   _TextureHeight       c26      1
//   _GradientScale       c27      1
//   _FaceShininess       c28      1
//   _OutlineShininess    c29      1
//   _LightTexture0       s0       1
//   _LightTextureB0      s1       1
//   _FaceTex             s2       1
//   _OutlineTex          s3       1
//   _BumpMap             s4       1
//   _MainTex             s5       1
//

    ps_3_0
    def c30, 10000, 0.00999999978, 2, -1
    def c31, 0.249999955, 0.25, 6.28318548, -3.14159274
    def c32, -2.52398507e-007, 2.47609005e-005, -0.00138883968, 0.0416666418
    def c33, 128, 0, 0, 0
    def c34, 0, 0.5, 1, -9.99999975e-005
    dcl_texcoord v0
    dcl_texcoord1_pp v1.xyz
    dcl_texcoord2_pp v2.xyz
    dcl_texcoord3_pp v3.xyz
    dcl_texcoord4 v4.xyz
    dcl_color_pp v5
    dcl_texcoord5 v6.xy
    dcl_cube s0
    dcl_2d s1
    dcl_2d s2
    dcl_2d s3
    dcl_2d s4
    dcl_2d s5
    add r0.x, c17.x, v6.x
    rcp r1.x, c25.x
    rcp r1.w, c26.x
    mov r1.yz, c34.x
    add r2, -r1, v0.xyxy
    add r1, r1, v0.xyxy
    texld r3, r2, s5
    texld r2, r2.zwzw, s5
    mov r2.z, r2.w
    mov r2.x, r3.w
    texld r3, r1, s5
    texld r1, r1.zwzw, s5
    mov r2.w, r1.w
    mov r2.y, r3.w
    add r0, r0.x, r2
    mov r1.x, c15.x
    add r1.y, r1.x, c18.x
    max r2.x, c30.y, r1.y
    rcp r1.y, r2.x
    mul r1.z, r2.x, c16.x
    mul r1.z, r1.z, c27.x
    mul r1.z, r1.z, -c30.z
    lrp_sat r2, r1.y, r0, c34.y
    mad r0, r2, c30.z, c30.w
    add r0, -r0_abs, c34.z
    mov r3.yz, c34
    mul r1.y, r3.y, c23.x
    frc r1.y, r1_abs.y
    cmp r1.y, c23.x, r1.y, -r1.y
    add r1.y, r1.y, -c34.y
    cmp r0, r1.y, r0, r2
    mad r2, r0, c31.x, c31.y
    frc r2, r2
    mad r2, r2, c31.z, c31.w
    mul r2, r2, r2
    mad r4, r2, c32.x, c32.y
    mad r4, r2, r4, c32.z
    mad r4, r2, r4, c32.w
    mad r4, r2, r4, -c34.y
    mad r2, r2, r4, c34.z
    lrp r4, c20.x, r2, r0
    add r0.x, r3.z, -c19.x
    min r2, r0.x, r4
    mul r0.xy, r1.z, r2.xzzw
    mad r0.xy, r2.ywzw, r1.z, -r0
    mov r0.w, -c34.z
    dp2add r1.y, r0.wyzw, r0.wyzw, c34.x
    mul r2.xyz, r0.wyww, c34.zzxw
    rsq r0.y, r1.y
    mul r1.yzw, r0.y, r2.xxyz
    mov r0.z, c34.z
    dp2add r0.y, r0.zxzw, r0.zxzw, c34.x
    rsq r0.y, r0.y
    mul r2.x, r0.y, r0.x
    mul r2.yz, r0.y, c34.xzxw
    mul r0.xyz, r1.yzww, r2
    mad r0.xyz, r2.zxyw, r1.zwyw, -r0
    mov r1.y, c3.y
    mad r2.x, c12.x, r1.y, v0.z
    mad r2.y, c13.x, r1.y, v0.w
    texld r2, r2, s3
    mul_pp r2.xyz, r2, c14
    mul r0.w, c14.w, v5.w
    mul_pp r3.w, r2.w, r0.w
    mul_pp r3.xyz, r2, r3.w
    mad r2.x, c8.x, r1.y, v0.z
    mad r2.y, c9.x, r1.y, v0.w
    texld r2, r2, s2
    mul r4, c10, v5
    mul_pp r2, r2, r4
    mul_pp r2.xyz, r2.w, r2
    mul r0.w, r1.x, c24.x
    mad r1.x, r0.w, -v6.y, c34.z
    mul_pp r0.w, r0.w, v6.y
    rsq r1.y, r0.w
    rcp_pp r1.y, r1.y
    cmp_pp r1.x, r1.x, r1.y, c34.z
    texld r4, v0, s5
    add r1.y, -r4.w, c34.y
    add r1.y, r1.y, -v6.x
    mad_pp r1.y, r1.y, v6.y, c34.y
    mad_sat_pp r1.z, r0.w, c34.y, r1.y
    mad_pp r0.w, r0.w, -c34.y, r1.y
    mul_pp r1.x, r1.x, r1.z
    lrp_pp r4, r1.x, r3, r2
    mov r1.x, c24.x
    mul r1.x, r1.x, c11.x
    mul_pp r1.y, r1.x, v6.y
    mad_pp r1.x, r1.x, v6.y, c34.z
    rcp r1.x, r1.x
    mad_pp r0.w, r1.y, c34.y, r0.w
    mul_sat_pp r0.w, r1.x, r0.w
    add_pp r0.w, -r0.w, c34.z
    mul_pp r2, r0.w, r4
    mad r0.w, r4.w, r0.w, c34.w
    mov r1.x, c22.x
    add r1.x, -r1.x, c21.x
    mad r1.x, r1.z, r1.x, c22.x
    texld_pp r3, v0.zwzw, s4
    mad_pp r3.xy, r3.wyzw, c30.z, c30.w
    dp2add_sat_pp r1.y, r3, r3, c34.x
    add_pp r1.y, -r1.y, c34.z
    rsq_pp r1.y, r1.y
    rcp_pp r3.z, r1.y
    mad r1.xyw, r3.xyzz, r1.x, -c34.xxzz
    mad r1.xyw, r2.w, r1, c34.xxzz
    add r0.xyz, r0, -r1.xyww
    nrm_pp r3.xyz, r0
    dp3_pp r0.x, v1, -r3
    dp3_pp r0.y, v2, -r3
    dp3_pp r0.z, v3, -r3
    add r1.xyw, c4.xyzz, -v4.xyzz
    dp3 r3.x, r1.xyww, r1.xyww
    rsq r3.x, r3.x
    add r3.yzw, c5.xxyz, -v4.xxyz
    nrm_pp r4.xyz, r3.yzww
    mad_pp r1.xyw, r1, r3.x, r4.xyzz
    dp3_pp r3.x, r0, r4
    max_pp r4.x, r3.x, c34.x
    nrm_pp r3.xyz, r1.xyww
    dp3_pp r0.x, r0, r3
    max r1.x, r0.x, c34.x
    mov r0.x, c28.x
    add r0.x, -r0.x, c29.x
    mad_pp r0.x, r1.z, r0.x, c28.x
    mul r0.x, r0.x, c33.x
    pow r3.x, r1.x, r0.x
    mad r1, v4.xyzx, c34.zzzx, c34.xxxz
    dp4 r0.x, c0, r1
    dp4 r0.y, c1, r1
    dp4 r0.z, c2, r1
    dp3 r1.x, r0, r0
    texld r5, r0, s0
    texld r1, r1.x, s1
    mul_pp r0.x, r5.w, r1.x
    mul_pp r0.xyz, r0.x, c6
    mul r1.xyz, r0, c7
    mul r1.xyz, r3.x, r1
    rcp r1.w, r2.w
    cmp r0.w, r0.w, r1.w, c30.x
    mul_pp r2.xyz, r0.w, r2
    mov_pp oC0.w, r2.w
    mul_pp r0.xyz, r0, r2
    mad_pp oC0.xyz, r0, r4.x, r1

// approximately 155 instruction slots used (10 texture, 145 arithmetic)
"
}
SubProgram "d3d11 " {
// Stats: 113 math, 10 textures
Keywords { "POINT_COOKIE" }
SetTexture 0 [_MainTex] 2D 5
SetTexture 1 [_FaceTex] 2D 2
SetTexture 2 [_OutlineTex] 2D 3
SetTexture 3 [_BumpMap] 2D 4
SetTexture 4 [_LightTextureB0] 2D 1
SetTexture 5 [_LightTexture0] CUBE 0
ConstBuffer "$Globals" 656
Matrix 128 [_LightMatrix0]
Vector 96 [_LightColor0]
Vector 112 [_SpecColor]
Float 192 [_FaceUVSpeedX]
Float 196 [_FaceUVSpeedY]
Vector 208 [_FaceColor]
Float 228 [_OutlineSoftness]
Float 232 [_OutlineUVSpeedX]
Float 236 [_OutlineUVSpeedY]
Vector 240 [_OutlineColor]
Float 256 [_OutlineWidth]
Float 260 [_Bevel]
Float 264 [_BevelOffset]
Float 268 [_BevelWidth]
Float 272 [_BevelClamp]
Float 276 [_BevelRoundness]
Float 280 [_BumpOutline]
Float 284 [_BumpFace]
Float 512 [_ShaderFlags]
Float 524 [_ScaleRatioA]
Float 584 [_TextureWidth]
Float 588 [_TextureHeight]
Float 592 [_GradientScale]
Float 608 [_FaceShininess]
Float 612 [_OutlineShininess]
ConstBuffer "UnityPerCamera" 144
Vector 0 [_Time]
Vector 64 [_WorldSpaceCameraPos] 3
ConstBuffer "UnityLighting" 720
Vector 0 [_WorldSpaceLightPos0]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityLighting" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
      ps_4_0
      dcl_constantbuffer cb0[39], immediateIndexed
      dcl_constantbuffer cb1[5], immediateIndexed
      dcl_constantbuffer cb2[1], immediateIndexed
      dcl_sampler s0, mode_default
      dcl_sampler s1, mode_default
      dcl_sampler s2, mode_default
      dcl_sampler s3, mode_default
      dcl_sampler s4, mode_default
      dcl_sampler s5, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_resource_texture2d (float,float,float,float) t1
      dcl_resource_texture2d (float,float,float,float) t2
      dcl_resource_texture2d (float,float,float,float) t3
      dcl_resource_texture2d (float,float,float,float) t4
      dcl_resource_texturecube (float,float,float,float) t5
      dcl_input_ps linear v1.xyzw
      dcl_input_ps linear v2.xyz
      dcl_input_ps linear v3.xyz
      dcl_input_ps linear v4.xyz
      dcl_input_ps linear v5.xyz
      dcl_input_ps linear v6.xyzw
      dcl_input_ps linear v7.xy
      dcl_output o0.xyzw
      dcl_temps 5
   0: add r0.x, v7.x, cb0[16].z
   1: div r1.xy, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[36].zwzz
   2: mov r1.z, l(0)
   3: add r2.xyzw, -r1.xzzy, v1.xyxy
   4: add r1.xyzw, r1.xzzy, v1.xyxy
   5: sample r3.xyzw, r2.xyxx, t0.wxyz, s5
   6: sample r2.xyzw, r2.zwzz, t0.xyzw, s5
   7: mov r3.z, r2.w
   8: sample r2.xyzw, r1.xyxx, t0.xyzw, s5
   9: sample r1.xyzw, r1.zwzz, t0.xyzw, s5
  10: mov r3.w, r1.w
  11: mov r3.y, r2.w
  12: add r0.xyzw, r0.xxxx, r3.xyzw
  13: add r0.xyzw, r0.xyzw, l(-0.500000, -0.500000, -0.500000, -0.500000)
  14: add r1.x, cb0[16].w, cb0[16].x
  15: max r1.x, r1.x, l(0.010000)
  16: div r0.xyzw, r0.xyzw, r1.xxxx
  17: mul r1.x, r1.x, cb0[16].y
  18: mul r1.x, r1.x, cb0[37].x
  19: mul r1.x, r1.x, l(-2.000000)
  20: add_sat r0.xyzw, r0.xyzw, l(0.500000, 0.500000, 0.500000, 0.500000)
  21: mad r2.xyzw, r0.xyzw, l(2.000000, 2.000000, 2.000000, 2.000000), l(-1.000000, -1.000000, -1.000000, -1.000000)
  22: add r2.xyzw, -|r2.xyzw|, l(1.000000, 1.000000, 1.000000, 1.000000)
  23: mul r1.y, cb0[32].x, l(0.500000)
  24: ge r1.z, r1.y, -r1.y
  25: frc r1.y, |r1.y|
  26: movc r1.y, r1.z, r1.y, -r1.y
  27: ge r1.y, r1.y, l(0.500000)
  28: movc r0.xyzw, r1.yyyy, r2.xyzw, r0.xyzw
  29: mul r2.xyzw, r0.xyzw, l(1.570796, 1.570796, 1.570796, 1.570796)
  30: sincos r2.xyzw, null, r2.xyzw
  31: add r2.xyzw, -r0.xyzw, r2.xyzw
  32: mad r0.xyzw, cb0[17].yyyy, r2.xyzw, r0.xyzw
  33: add r1.y, -cb0[17].x, l(1.000000)
  34: min r0.xyzw, r0.xyzw, r1.yyyy
  35: mul r0.xz, r1.xxxx, r0.xxzx
  36: mad r0.yz, r0.wwyw, r1.xxxx, -r0.zzxz
  37: mov r0.xw, l(-1.000000,0,0,1.000000)
  38: dp2 r1.x, r0.xyxx, r0.xyxx
  39: rsq r1.x, r1.x
  40: dp2 r0.w, r0.zwzz, r0.zwzz
  41: rsq r0.w, r0.w
  42: mul r2.x, r0.w, r0.z
  43: mul r2.yz, r0.wwww, l(0.000000, 1.000000, 0.000000, 0.000000)
  44: mov r0.z, l(0)
  45: mul r0.xyz, r1.xxxx, r0.xyzx
  46: mul r1.xyz, r0.xyzx, r2.xyzx
  47: mad r0.xyz, r2.zxyz, r0.yzxy, -r1.xyzx
  48: mad r1.xy, cb0[14].zwzz, cb1[0].yyyy, v1.zwzz
  49: sample r1.xyzw, r1.xyxx, t2.xyzw, s3
  50: mul r1.xyz, r1.xyzx, cb0[15].xyzx
  51: mul r0.w, v6.w, cb0[15].w
  52: mul r2.w, r1.w, r0.w
  53: mul r2.xyz, r1.xyzx, r2.wwww
  54: mad r1.xy, cb0[12].xyxx, cb1[0].yyyy, v1.zwzz
  55: sample r1.xyzw, r1.xyxx, t1.xyzw, s2
  56: mul r3.xyzw, v6.xyzw, cb0[13].xyzw
  57: mul r1.xyzw, r1.xyzw, r3.xyzw
  58: mul r1.xyz, r1.wwww, r1.xyzx
  59: add r2.xyzw, -r1.xyzw, r2.xyzw
  60: mul r0.w, cb0[16].x, cb0[32].w
  61: mul r0.w, r0.w, v7.y
  62: min r3.x, r0.w, l(1.000000)
  63: sqrt r3.x, r3.x
  64: sample r4.xyzw, v1.xyxx, t0.xyzw, s5
  65: add r3.y, -r4.w, l(0.500000)
  66: add r3.y, r3.y, -v7.x
  67: mad r3.y, r3.y, v7.y, l(0.500000)
  68: mad_sat r3.z, r0.w, l(0.500000), r3.y
  69: mad r0.w, -r0.w, l(0.500000), r3.y
  70: mul r3.x, r3.x, r3.z
  71: mad r1.xyzw, r3.xxxx, r2.xyzw, r1.xyzw
  72: mul r2.x, cb0[14].y, cb0[32].w
  73: mul r2.y, r2.x, v7.y
  74: mad r2.x, r2.x, v7.y, l(1.000000)
  75: mad r0.w, r2.y, l(0.500000), r0.w
  76: div_sat r0.w, r0.w, r2.x
  77: add r0.w, -r0.w, l(1.000000)
  78: mul r1.xyzw, r0.wwww, r1.xyzw
  79: add r0.w, -cb0[17].w, cb0[17].z
  80: mad r0.w, r3.z, r0.w, cb0[17].w
  81: sample r2.xyzw, v1.zwzz, t3.xyzw, s4
  82: mad r2.xy, r2.wyww, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
  83: dp2 r2.w, r2.xyxx, r2.xyxx
  84: min r2.w, r2.w, l(1.000000)
  85: add r2.w, -r2.w, l(1.000000)
  86: sqrt r2.z, r2.w
  87: mad r2.xyz, r2.xyzx, r0.wwww, l(-0.000000, -0.000000, -1.000000, 0.000000)
  88: mad r2.xyz, r1.wwww, r2.xyzx, l(0.000000, 0.000000, 1.000000, 0.000000)
  89: add r0.xyz, r0.xyzx, -r2.xyzx
  90: dp3 r0.w, r0.xyzx, r0.xyzx
  91: rsq r0.w, r0.w
  92: mul r0.xyz, r0.wwww, r0.xyzx
  93: dp3 r2.x, v2.xyzx, -r0.xyzx
  94: dp3 r2.y, v3.xyzx, -r0.xyzx
  95: dp3 r2.z, v4.xyzx, -r0.xyzx
  96: add r0.xyz, -v5.xyzx, cb2[0].xyzx
  97: dp3 r0.w, r0.xyzx, r0.xyzx
  98: rsq r0.w, r0.w
  99: mul r0.xyz, r0.wwww, r0.xyzx
 100: add r3.xyw, -v5.xyxz, cb1[4].xyxz
 101: dp3 r0.w, r3.xywx, r3.xywx
 102: rsq r0.w, r0.w
 103: mad r3.xyw, r3.xyxw, r0.wwww, r0.xyxz
 104: dp3 r0.x, r2.xyzx, r0.xyzx
 105: dp3 r0.y, r3.xywx, r3.xywx
 106: rsq r0.y, r0.y
 107: mul r0.yzw, r0.yyyy, r3.xxyw
 108: dp3 r0.y, r2.xyzx, r0.yzwy
 109: max r0.xy, r0.xyxx, l(0.000000, 0.000000, 0.000000, 0.000000)
 110: log r0.y, r0.y
 111: add r0.z, -cb0[38].x, cb0[38].y
 112: mad r0.z, r3.z, r0.z, cb0[38].x
 113: mul r0.z, r0.z, l(128.000000)
 114: mul r0.y, r0.y, r0.z
 115: exp r0.y, r0.y
 116: mul r2.xyz, v5.yyyy, cb0[9].xyzx
 117: mad r2.xyz, cb0[8].xyzx, v5.xxxx, r2.xyzx
 118: mad r2.xyz, cb0[10].xyzx, v5.zzzz, r2.xyzx
 119: add r2.xyz, r2.xyzx, cb0[11].xyzx
 120: dp3 r0.z, r2.xyzx, r2.xyzx
 121: sample r2.xyzw, r2.xyzx, t5.xyzw, s0
 122: sample r3.xyzw, r0.zzzz, t4.xyzw, s1
 123: mul r0.z, r2.w, r3.x
 124: mul r2.xyz, r0.zzzz, cb0[6].xyzx
 125: mul r3.xyz, r2.xyzx, cb0[7].xyzx
 126: mul r0.yzw, r0.yyyy, r3.xxyz
 127: max r2.w, r1.w, l(0.000100)
 128: div r1.xyz, r1.xyzx, r2.wwww
 129: mov o0.w, r1.w
 130: mul r1.xyz, r2.xyzx, r1.xyzx
 131: mad o0.xyz, r1.xyzx, r0.xxxx, r0.yzwy
 132: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
Keywords { "DIRECTIONAL_COOKIE" }
"// shader disassembly not supported on opengl"
}
SubProgram "d3d9 " {
// Stats: 141 math, 9 textures
Keywords { "DIRECTIONAL_COOKIE" }
Matrix 0 [_LightMatrix0] 2
Float 15 [_Bevel]
Float 18 [_BevelClamp]
Float 16 [_BevelOffset]
Float 19 [_BevelRoundness]
Float 17 [_BevelWidth]
Float 21 [_BumpFace]
Float 20 [_BumpOutline]
Vector 9 [_FaceColor]
Float 27 [_FaceShininess]
Float 7 [_FaceUVSpeedX]
Float 8 [_FaceUVSpeedY]
Float 26 [_GradientScale]
Vector 5 [_LightColor0]
Vector 13 [_OutlineColor]
Float 28 [_OutlineShininess]
Float 10 [_OutlineSoftness]
Float 11 [_OutlineUVSpeedX]
Float 12 [_OutlineUVSpeedY]
Float 14 [_OutlineWidth]
Float 23 [_ScaleRatioA]
Float 22 [_ShaderFlags]
Vector 6 [_SpecColor]
Float 25 [_TextureHeight]
Float 24 [_TextureWidth]
Vector 2 [_Time]
Vector 3 [_WorldSpaceCameraPos]
Vector 4 [_WorldSpaceLightPos0]
SetTexture 0 [_LightTexture0] 2D 0
SetTexture 1 [_FaceTex] 2D 1
SetTexture 2 [_OutlineTex] 2D 2
SetTexture 3 [_BumpMap] 2D 3
SetTexture 4 [_MainTex] 2D 4
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float _Bevel;
//   float _BevelClamp;
//   float _BevelOffset;
//   float _BevelRoundness;
//   float _BevelWidth;
//   float _BumpFace;
//   sampler2D _BumpMap;
//   float _BumpOutline;
//   float4 _FaceColor;
//   float _FaceShininess;
//   sampler2D _FaceTex;
//   float _FaceUVSpeedX;
//   float _FaceUVSpeedY;
//   float _GradientScale;
//   float4 _LightColor0;
//   row_major float4x4 _LightMatrix0;
//   sampler2D _LightTexture0;
//   sampler2D _MainTex;
//   float4 _OutlineColor;
//   float _OutlineShininess;
//   float _OutlineSoftness;
//   sampler2D _OutlineTex;
//   float _OutlineUVSpeedX;
//   float _OutlineUVSpeedY;
//   float _OutlineWidth;
//   float _ScaleRatioA;
//   float _ShaderFlags;
//   float4 _SpecColor;
//   float _TextureHeight;
//   float _TextureWidth;
//   float4 _Time;
//   float3 _WorldSpaceCameraPos;
//   float4 _WorldSpaceLightPos0;
//
//
// Registers:
//
//   Name                 Reg   Size
//   -------------------- ----- ----
//   _LightMatrix0        c0       2
//   _Time                c2       1
//   _WorldSpaceCameraPos c3       1
//   _WorldSpaceLightPos0 c4       1
//   _LightColor0         c5       1
//   _SpecColor           c6       1
//   _FaceUVSpeedX        c7       1
//   _FaceUVSpeedY        c8       1
//   _FaceColor           c9       1
//   _OutlineSoftness     c10      1
//   _OutlineUVSpeedX     c11      1
//   _OutlineUVSpeedY     c12      1
//   _OutlineColor        c13      1
//   _OutlineWidth        c14      1
//   _Bevel               c15      1
//   _BevelOffset         c16      1
//   _BevelWidth          c17      1
//   _BevelClamp          c18      1
//   _BevelRoundness      c19      1
//   _BumpOutline         c20      1
//   _BumpFace            c21      1
//   _ShaderFlags         c22      1
//   _ScaleRatioA         c23      1
//   _TextureWidth        c24      1
//   _TextureHeight       c25      1
//   _GradientScale       c26      1
//   _FaceShininess       c27      1
//   _OutlineShininess    c28      1
//   _LightTexture0       s0       1
//   _FaceTex             s1       1
//   _OutlineTex          s2       1
//   _BumpMap             s3       1
//   _MainTex             s4       1
//

    ps_3_0
    def c29, 10000, 0.00999999978, 2, -1
    def c30, 0.249999955, 0.25, 6.28318548, -3.14159274
    def c31, -2.52398507e-007, 2.47609005e-005, -0.00138883968, 0.0416666418
    def c32, 128, 0, 0, 0
    def c33, 0, 0.5, 1, -9.99999975e-005
    dcl_texcoord v0
    dcl_texcoord1_pp v1.xyz
    dcl_texcoord2_pp v2.xyz
    dcl_texcoord3_pp v3.xyz
    dcl_texcoord4 v4.xyz
    dcl_color_pp v5
    dcl_texcoord5 v6.xy
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    dcl_2d s3
    dcl_2d s4
    add r0.x, c16.x, v6.x
    rcp r1.x, c24.x
    rcp r1.w, c25.x
    mov r1.yz, c33.x
    add r2, -r1, v0.xyxy
    add r1, r1, v0.xyxy
    texld r3, r2, s4
    texld r2, r2.zwzw, s4
    mov r2.z, r2.w
    mov r2.x, r3.w
    texld r3, r1, s4
    texld r1, r1.zwzw, s4
    mov r2.w, r1.w
    mov r2.y, r3.w
    add r0, r0.x, r2
    mov r1.x, c14.x
    add r1.y, r1.x, c17.x
    max r2.x, c29.y, r1.y
    rcp r1.y, r2.x
    mul r1.z, r2.x, c15.x
    mul r1.z, r1.z, c26.x
    mul r1.z, r1.z, -c29.z
    lrp_sat r2, r1.y, r0, c33.y
    mad r0, r2, c29.z, c29.w
    add r0, -r0_abs, c33.z
    mov r3.yz, c33
    mul r1.y, r3.y, c22.x
    frc r1.y, r1_abs.y
    cmp r1.y, c22.x, r1.y, -r1.y
    add r1.y, r1.y, -c33.y
    cmp r0, r1.y, r0, r2
    mad r2, r0, c30.x, c30.y
    frc r2, r2
    mad r2, r2, c30.z, c30.w
    mul r2, r2, r2
    mad r4, r2, c31.x, c31.y
    mad r4, r2, r4, c31.z
    mad r4, r2, r4, c31.w
    mad r4, r2, r4, -c33.y
    mad r2, r2, r4, c33.z
    lrp r4, c19.x, r2, r0
    add r0.x, r3.z, -c18.x
    min r2, r0.x, r4
    mul r0.xy, r1.z, r2.xzzw
    mad r0.xy, r2.ywzw, r1.z, -r0
    mov r0.w, -c33.z
    dp2add r1.y, r0.wyzw, r0.wyzw, c33.x
    mul r2.xyz, r0.wyww, c33.zzxw
    rsq r0.y, r1.y
    mul r1.yzw, r0.y, r2.xxyz
    mov r0.z, c33.z
    dp2add r0.y, r0.zxzw, r0.zxzw, c33.x
    rsq r0.y, r0.y
    mul r2.x, r0.y, r0.x
    mul r2.yz, r0.y, c33.xzxw
    mul r0.xyz, r1.yzww, r2
    mad r0.xyz, r2.zxyw, r1.zwyw, -r0
    mov r1.y, c2.y
    mad r2.x, c11.x, r1.y, v0.z
    mad r2.y, c12.x, r1.y, v0.w
    texld r2, r2, s2
    mul_pp r2.xyz, r2, c13
    mul r0.w, c13.w, v5.w
    mul_pp r3.w, r2.w, r0.w
    mul_pp r3.xyz, r2, r3.w
    mad r2.x, c7.x, r1.y, v0.z
    mad r2.y, c8.x, r1.y, v0.w
    texld r2, r2, s1
    mul r4, c9, v5
    mul_pp r2, r2, r4
    mul_pp r2.xyz, r2.w, r2
    mul r0.w, r1.x, c23.x
    mad r1.x, r0.w, -v6.y, c33.z
    mul_pp r0.w, r0.w, v6.y
    rsq r1.y, r0.w
    rcp_pp r1.y, r1.y
    cmp_pp r1.x, r1.x, r1.y, c33.z
    texld r4, v0, s4
    add r1.y, -r4.w, c33.y
    add r1.y, r1.y, -v6.x
    mad_pp r1.y, r1.y, v6.y, c33.y
    mad_sat_pp r1.z, r0.w, c33.y, r1.y
    mad_pp r0.w, r0.w, -c33.y, r1.y
    mul_pp r1.x, r1.x, r1.z
    lrp_pp r4, r1.x, r3, r2
    mov r1.x, c23.x
    mul r1.x, r1.x, c10.x
    mul_pp r1.y, r1.x, v6.y
    mad_pp r1.x, r1.x, v6.y, c33.z
    rcp r1.x, r1.x
    mad_pp r0.w, r1.y, c33.y, r0.w
    mul_sat_pp r0.w, r1.x, r0.w
    add_pp r0.w, -r0.w, c33.z
    mul_pp r2, r0.w, r4
    mad r0.w, r4.w, r0.w, c33.w
    mov r1.x, c21.x
    add r1.x, -r1.x, c20.x
    mad r1.x, r1.z, r1.x, c21.x
    texld_pp r3, v0.zwzw, s3
    mad_pp r3.xy, r3.wyzw, c29.z, c29.w
    dp2add_sat_pp r1.y, r3, r3, c33.x
    add_pp r1.y, -r1.y, c33.z
    rsq_pp r1.y, r1.y
    rcp_pp r3.z, r1.y
    mad r1.xyw, r3.xyzz, r1.x, -c33.xxzz
    mad r1.xyw, r2.w, r1, c33.xxzz
    add r0.xyz, r0, -r1.xyww
    nrm_pp r3.xyz, r0
    dp3_pp r0.x, v1, -r3
    dp3_pp r0.y, v2, -r3
    dp3_pp r0.z, v3, -r3
    add r1.xyw, c3.xyzz, -v4.xyzz
    dp3 r3.x, r1.xyww, r1.xyww
    rsq r3.x, r3.x
    mad_pp r1.xyw, r1, r3.x, c4.xyzz
    nrm_pp r3.xyz, r1.xyww
    dp3_pp r1.x, r0, r3
    dp3_pp r0.x, r0, c4
    max_pp r1.y, r0.x, c33.x
    max r0.x, r1.x, c33.x
    mov r1.x, c27.x
    add r0.y, -r1.x, c28.x
    mad_pp r0.y, r1.z, r0.y, c27.x
    mul r0.y, r0.y, c32.x
    pow r1.x, r0.x, r0.y
    mad r3, v4.xyzx, c33.zzzx, c33.xxxz
    dp4 r0.x, c0, r3
    dp4 r0.y, c1, r3
    texld_pp r3, r0, s0
    mul_pp r0.xyz, r3.w, c5
    mul r3.xyz, r0, c6
    mul r1.xzw, r1.x, r3.xyyz
    rcp r3.x, r2.w
    cmp r0.w, r0.w, r3.x, c29.x
    mul_pp r2.xyz, r0.w, r2
    mov_pp oC0.w, r2.w
    mul_pp r0.xyz, r0, r2
    mad_pp oC0.xyz, r0, r1.y, r1.xzww

// approximately 147 instruction slots used (9 texture, 138 arithmetic)
"
}
SubProgram "d3d11 " {
// Stats: 107 math, 9 textures
Keywords { "DIRECTIONAL_COOKIE" }
SetTexture 0 [_MainTex] 2D 4
SetTexture 1 [_FaceTex] 2D 1
SetTexture 2 [_OutlineTex] 2D 2
SetTexture 3 [_BumpMap] 2D 3
SetTexture 4 [_LightTexture0] 2D 0
ConstBuffer "$Globals" 656
Matrix 128 [_LightMatrix0]
Vector 96 [_LightColor0]
Vector 112 [_SpecColor]
Float 192 [_FaceUVSpeedX]
Float 196 [_FaceUVSpeedY]
Vector 208 [_FaceColor]
Float 228 [_OutlineSoftness]
Float 232 [_OutlineUVSpeedX]
Float 236 [_OutlineUVSpeedY]
Vector 240 [_OutlineColor]
Float 256 [_OutlineWidth]
Float 260 [_Bevel]
Float 264 [_BevelOffset]
Float 268 [_BevelWidth]
Float 272 [_BevelClamp]
Float 276 [_BevelRoundness]
Float 280 [_BumpOutline]
Float 284 [_BumpFace]
Float 512 [_ShaderFlags]
Float 524 [_ScaleRatioA]
Float 584 [_TextureWidth]
Float 588 [_TextureHeight]
Float 592 [_GradientScale]
Float 608 [_FaceShininess]
Float 612 [_OutlineShininess]
ConstBuffer "UnityPerCamera" 144
Vector 0 [_Time]
Vector 64 [_WorldSpaceCameraPos] 3
ConstBuffer "UnityLighting" 720
Vector 0 [_WorldSpaceLightPos0]
BindCB  "$Globals" 0
BindCB  "UnityPerCamera" 1
BindCB  "UnityLighting" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xyz         4     NONE   float   xyz 
// TEXCOORD                 4   xyz         5     NONE   float   xyz 
// COLOR                    0   xyzw        6     NONE   float   xyzw
// TEXCOORD                 5   xy          7     NONE   float   xy  
// TEXCOORD                 6   xyz         8     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
      ps_4_0
      dcl_constantbuffer cb0[39], immediateIndexed
      dcl_constantbuffer cb1[5], immediateIndexed
      dcl_constantbuffer cb2[1], immediateIndexed
      dcl_sampler s0, mode_default
      dcl_sampler s1, mode_default
      dcl_sampler s2, mode_default
      dcl_sampler s3, mode_default
      dcl_sampler s4, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_resource_texture2d (float,float,float,float) t1
      dcl_resource_texture2d (float,float,float,float) t2
      dcl_resource_texture2d (float,float,float,float) t3
      dcl_resource_texture2d (float,float,float,float) t4
      dcl_input_ps linear v1.xyzw
      dcl_input_ps linear v2.xyz
      dcl_input_ps linear v3.xyz
      dcl_input_ps linear v4.xyz
      dcl_input_ps linear v5.xyz
      dcl_input_ps linear v6.xyzw
      dcl_input_ps linear v7.xy
      dcl_output o0.xyzw
      dcl_temps 5
   0: add r0.x, v7.x, cb0[16].z
   1: div r1.xy, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[36].zwzz
   2: mov r1.z, l(0)
   3: add r2.xyzw, -r1.xzzy, v1.xyxy
   4: add r1.xyzw, r1.xzzy, v1.xyxy
   5: sample r3.xyzw, r2.xyxx, t0.wxyz, s4
   6: sample r2.xyzw, r2.zwzz, t0.xyzw, s4
   7: mov r3.z, r2.w
   8: sample r2.xyzw, r1.xyxx, t0.xyzw, s4
   9: sample r1.xyzw, r1.zwzz, t0.xyzw, s4
  10: mov r3.w, r1.w
  11: mov r3.y, r2.w
  12: add r0.xyzw, r0.xxxx, r3.xyzw
  13: add r0.xyzw, r0.xyzw, l(-0.500000, -0.500000, -0.500000, -0.500000)
  14: add r1.x, cb0[16].w, cb0[16].x
  15: max r1.x, r1.x, l(0.010000)
  16: div r0.xyzw, r0.xyzw, r1.xxxx
  17: mul r1.x, r1.x, cb0[16].y
  18: mul r1.x, r1.x, cb0[37].x
  19: mul r1.x, r1.x, l(-2.000000)
  20: add_sat r0.xyzw, r0.xyzw, l(0.500000, 0.500000, 0.500000, 0.500000)
  21: mad r2.xyzw, r0.xyzw, l(2.000000, 2.000000, 2.000000, 2.000000), l(-1.000000, -1.000000, -1.000000, -1.000000)
  22: add r2.xyzw, -|r2.xyzw|, l(1.000000, 1.000000, 1.000000, 1.000000)
  23: mul r1.y, cb0[32].x, l(0.500000)
  24: ge r1.z, r1.y, -r1.y
  25: frc r1.y, |r1.y|
  26: movc r1.y, r1.z, r1.y, -r1.y
  27: ge r1.y, r1.y, l(0.500000)
  28: movc r0.xyzw, r1.yyyy, r2.xyzw, r0.xyzw
  29: mul r2.xyzw, r0.xyzw, l(1.570796, 1.570796, 1.570796, 1.570796)
  30: sincos r2.xyzw, null, r2.xyzw
  31: add r2.xyzw, -r0.xyzw, r2.xyzw
  32: mad r0.xyzw, cb0[17].yyyy, r2.xyzw, r0.xyzw
  33: add r1.y, -cb0[17].x, l(1.000000)
  34: min r0.xyzw, r0.xyzw, r1.yyyy
  35: mul r0.xz, r1.xxxx, r0.xxzx
  36: mad r0.yz, r0.wwyw, r1.xxxx, -r0.zzxz
  37: mov r0.xw, l(-1.000000,0,0,1.000000)
  38: dp2 r1.x, r0.xyxx, r0.xyxx
  39: rsq r1.x, r1.x
  40: dp2 r0.w, r0.zwzz, r0.zwzz
  41: rsq r0.w, r0.w
  42: mul r2.x, r0.w, r0.z
  43: mul r2.yz, r0.wwww, l(0.000000, 1.000000, 0.000000, 0.000000)
  44: mov r0.z, l(0)
  45: mul r0.xyz, r1.xxxx, r0.xyzx
  46: mul r1.xyz, r0.xyzx, r2.xyzx
  47: mad r0.xyz, r2.zxyz, r0.yzxy, -r1.xyzx
  48: mad r1.xy, cb0[14].zwzz, cb1[0].yyyy, v1.zwzz
  49: sample r1.xyzw, r1.xyxx, t2.xyzw, s2
  50: mul r1.xyz, r1.xyzx, cb0[15].xyzx
  51: mul r0.w, v6.w, cb0[15].w
  52: mul r2.w, r1.w, r0.w
  53: mul r2.xyz, r1.xyzx, r2.wwww
  54: mad r1.xy, cb0[12].xyxx, cb1[0].yyyy, v1.zwzz
  55: sample r1.xyzw, r1.xyxx, t1.xyzw, s1
  56: mul r3.xyzw, v6.xyzw, cb0[13].xyzw
  57: mul r1.xyzw, r1.xyzw, r3.xyzw
  58: mul r1.xyz, r1.wwww, r1.xyzx
  59: add r2.xyzw, -r1.xyzw, r2.xyzw
  60: mul r0.w, cb0[16].x, cb0[32].w
  61: mul r0.w, r0.w, v7.y
  62: min r3.x, r0.w, l(1.000000)
  63: sqrt r3.x, r3.x
  64: sample r4.xyzw, v1.xyxx, t0.xyzw, s4
  65: add r3.y, -r4.w, l(0.500000)
  66: add r3.y, r3.y, -v7.x
  67: mad r3.y, r3.y, v7.y, l(0.500000)
  68: mad_sat r3.z, r0.w, l(0.500000), r3.y
  69: mad r0.w, -r0.w, l(0.500000), r3.y
  70: mul r3.x, r3.x, r3.z
  71: mad r1.xyzw, r3.xxxx, r2.xyzw, r1.xyzw
  72: mul r2.x, cb0[14].y, cb0[32].w
  73: mul r2.y, r2.x, v7.y
  74: mad r2.x, r2.x, v7.y, l(1.000000)
  75: mad r0.w, r2.y, l(0.500000), r0.w
  76: div_sat r0.w, r0.w, r2.x
  77: add r0.w, -r0.w, l(1.000000)
  78: mul r1.xyzw, r0.wwww, r1.xyzw
  79: add r0.w, -cb0[17].w, cb0[17].z
  80: mad r0.w, r3.z, r0.w, cb0[17].w
  81: sample r2.xyzw, v1.zwzz, t3.xyzw, s3
  82: mad r2.xy, r2.wyww, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
  83: dp2 r2.w, r2.xyxx, r2.xyxx
  84: min r2.w, r2.w, l(1.000000)
  85: add r2.w, -r2.w, l(1.000000)
  86: sqrt r2.z, r2.w
  87: mad r2.xyz, r2.xyzx, r0.wwww, l(-0.000000, -0.000000, -1.000000, 0.000000)
  88: mad r2.xyz, r1.wwww, r2.xyzx, l(0.000000, 0.000000, 1.000000, 0.000000)
  89: add r0.xyz, r0.xyzx, -r2.xyzx
  90: dp3 r0.w, r0.xyzx, r0.xyzx
  91: rsq r0.w, r0.w
  92: mul r0.xyz, r0.wwww, r0.xyzx
  93: dp3 r2.x, v2.xyzx, -r0.xyzx
  94: dp3 r2.y, v3.xyzx, -r0.xyzx
  95: dp3 r2.z, v4.xyzx, -r0.xyzx
  96: add r0.xyz, -v5.xyzx, cb1[4].xyzx
  97: dp3 r0.w, r0.xyzx, r0.xyzx
  98: rsq r0.w, r0.w
  99: mad r0.xyz, r0.xyzx, r0.wwww, cb2[0].xyzx
 100: dp3 r0.w, r0.xyzx, r0.xyzx
 101: rsq r0.w, r0.w
 102: mul r0.xyz, r0.wwww, r0.xyzx
 103: dp3 r0.x, r2.xyzx, r0.xyzx
 104: dp3 r0.y, r2.xyzx, cb2[0].xyzx
 105: max r0.xy, r0.xyxx, l(0.000000, 0.000000, 0.000000, 0.000000)
 106: log r0.x, r0.x
 107: add r0.z, -cb0[38].x, cb0[38].y
 108: mad r0.z, r3.z, r0.z, cb0[38].x
 109: mul r0.z, r0.z, l(128.000000)
 110: mul r0.x, r0.x, r0.z
 111: exp r0.x, r0.x
 112: mul r0.zw, v5.yyyy, cb0[9].xxxy
 113: mad r0.zw, cb0[8].xxxy, v5.xxxx, r0.zzzw
 114: mad r0.zw, cb0[10].xxxy, v5.zzzz, r0.zzzw
 115: add r0.zw, r0.zzzw, cb0[11].xxxy
 116: sample r2.xyzw, r0.zwzz, t4.xyzw, s0
 117: mul r2.xyz, r2.wwww, cb0[6].xyzx
 118: mul r3.xyz, r2.xyzx, cb0[7].xyzx
 119: mul r0.xzw, r0.xxxx, r3.xxyz
 120: max r2.w, r1.w, l(0.000100)
 121: div r1.xyz, r1.xyzx, r2.wwww
 122: mov o0.w, r1.w
 123: mul r1.xyz, r2.xyzx, r1.xyzx
 124: mad o0.xyz, r1.xyzx, r0.yyyy, r0.xzwx
 125: ret 
// Approximately 0 instruction slots used
"
}
}
 }


 // Stats for Vertex shader:
 //       d3d11 : 13 math
 //    d3d11_9x : 13 math
 //        d3d9 : 17 avg math (14..21)
 //      opengl : 4 avg math (3..6), 2 texture, 1 branch
 // Stats for Fragment shader:
 //       d3d11 : 4 avg math (2..6), 1 texture
 //    d3d11_9x : 4 avg math (2..6), 1 texture
 //        d3d9 : 5 avg math (4..7), 2 texture
 Pass {
  Name "CASTER"
  Tags { "LIGHTMODE"="SHADOWCASTER" "QUEUE"="Transparent" "IGNOREPROJECTOR"="true" "SHADOWSUPPORT"="true" "RenderType"="Transparent" }
  AlphaToMask On
  Cull Off
  Stencil {
   Ref 2
   ReadMask 1
   WriteMask 3
   Pass Replace
   ZFail Replace
  }
  Blend SrcAlpha OneMinusSrcAlpha
  ColorMask RGB
  Offset 1, 1
  GpuProgramID 188831
Program "vp" {
SubProgram "opengl " {
// Stats: 3 math, 2 textures, 1 branches
Keywords { "SHADOWS_DEPTH" }
"#version 120

#ifdef VERTEX
uniform vec4 unity_LightShadowBias;

uniform vec4 _MainTex_ST;
uniform float _OutlineWidth;
uniform float _FaceDilate;
uniform float _ScaleRatioA;
varying vec2 xlv_TEXCOORD1;
varying float xlv_TEXCOORD2;
void main ()
{
  vec4 tmpvar_1;
  vec4 tmpvar_2;
  tmpvar_2.w = 1.0;
  tmpvar_2.xyz = gl_Vertex.xyz;
  tmpvar_1 = (gl_ModelViewProjectionMatrix * tmpvar_2);
  vec4 clipPos_3;
  clipPos_3.xyw = tmpvar_1.xyw;
  clipPos_3.z = (tmpvar_1.z + clamp ((unity_LightShadowBias.x / tmpvar_1.w), 0.0, 1.0));
  clipPos_3.z = mix (clipPos_3.z, max (clipPos_3.z, -(tmpvar_1.w)), unity_LightShadowBias.y);
  tmpvar_1 = clipPos_3;
  gl_Position = clipPos_3;
  xlv_TEXCOORD1 = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  xlv_TEXCOORD2 = (((1.0 - 
    (_OutlineWidth * _ScaleRatioA)
  ) - (_FaceDilate * _ScaleRatioA)) / 2.0);
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
varying vec2 xlv_TEXCOORD1;
varying float xlv_TEXCOORD2;
void main ()
{
  float x_1;
  x_1 = (texture2D (_MainTex, xlv_TEXCOORD1).w - xlv_TEXCOORD2);
  if ((x_1 < 0.0)) {
    discard;
  };
  gl_FragData[0] = vec4(0.0, 0.0, 0.0, 0.0);
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 21 math
Keywords { "SHADOWS_DEPTH" }
Bind "vertex" Vertex
Bind "texcoord" TexCoord0
Matrix 0 [glstate_matrix_mvp]
Float 7 [_FaceDilate]
Vector 5 [_MainTex_ST]
Float 6 [_OutlineWidth]
Float 8 [_ScaleRatioA]
Vector 4 [unity_LightShadowBias]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float _FaceDilate;
//   float4 _MainTex_ST;
//   float _OutlineWidth;
//   float _ScaleRatioA;
//   row_major float4x4 glstate_matrix_mvp;
//   float4 unity_LightShadowBias;
//
//
// Registers:
//
//   Name                  Reg   Size
//   --------------------- ----- ----
//   glstate_matrix_mvp    c0       4
//   unity_LightShadowBias c4       1
//   _MainTex_ST           c5       1
//   _OutlineWidth         c6       1
//   _FaceDilate           c7       1
//   _ScaleRatioA          c8       1
//

    vs_2_0
    def c9, 1, 0, 0.5, 0
    dcl_position v0
    dcl_texcoord v1
    mad oT1.xy, v1, c5, c5.zwzw
    mov r0.x, c9.x
    mov r1.x, c8.x
    mad r0.x, c6.x, -r1.x, r0.x
    mad r0.x, c7.x, -r1.x, r0.x
    mul oT2.x, r0.x, c9.z
    mad r0, v0.xyzx, c9.xxxy, c9.yyyx
    dp4 r1.w, c3, r0
    rcp r2.x, r1.w
    mul r2.x, r2.x, c4.x
    max r2.x, r2.x, c9.y
    min r2.x, r2.x, c9.x
    dp4 r2.y, c2, r0
    add r2.x, r2.x, r2.y
    max r2.y, r2.x, c9.y
    lrp r1.z, c4.y, r2.y, r2.x
    dp4 r1.x, c0, r0
    dp4 r1.y, c1, r0
    mov oT0, r1
    mov oPos, r1

// approximately 20 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 13 math
Keywords { "SHADOWS_DEPTH" }
Bind "vertex" Vertex
Bind "texcoord" TexCoord0
ConstBuffer "$Globals" 128
Vector 96 [_MainTex_ST]
Float 112 [_OutlineWidth]
Float 116 [_FaceDilate]
Float 120 [_ScaleRatioA]
ConstBuffer "UnityShadows" 416
Vector 80 [unity_LightShadowBias]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
BindCB  "$Globals" 0
BindCB  "UnityShadows" 1
BindCB  "UnityPerDraw" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyz 
// NORMAL                   0   xyz         1     NONE   float       
// TEXCOORD                 0   xyzw        2     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 1   xy          1     NONE   float   xy  
// TEXCOORD                 2     z         1     NONE   float     z 
//
      vs_4_0
      dcl_constantbuffer cb0[8], immediateIndexed
      dcl_constantbuffer cb1[6], immediateIndexed
      dcl_constantbuffer cb2[4], immediateIndexed
      dcl_input v0.xyz
      dcl_input v2.xy
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xy
      dcl_output o1.z
      dcl_temps 2
   0: mul r0.xyzw, v0.yyyy, cb2[1].xyzw
   1: mad r0.xyzw, cb2[0].xyzw, v0.xxxx, r0.xyzw
   2: mad r0.xyzw, cb2[2].xyzw, v0.zzzz, r0.xyzw
   3: add r0.xyzw, r0.xyzw, cb2[3].xyzw
   4: div_sat r1.x, cb1[5].x, r0.w
   5: add r0.z, r0.z, r1.x
   6: mov o0.xyw, r0.xyxw
   7: max r0.x, r0.z, l(0.000000)
   8: add r0.x, -r0.z, r0.x
   9: mad o0.z, cb1[5].y, r0.x, r0.z
  10: mad r0.x, -cb0[7].x, cb0[7].z, l(1.000000)
  11: mad r0.x, -cb0[7].y, cb0[7].z, r0.x
  12: mul o1.z, r0.x, l(0.500000)
  13: mad o1.xy, v2.xyxx, cb0[6].xyxx, cb0[6].zwzz
  14: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "d3d11_9x " {
// Stats: 13 math
Keywords { "SHADOWS_DEPTH" }
Bind "vertex" Vertex
Bind "texcoord" TexCoord0
ConstBuffer "$Globals" 128
Vector 96 [_MainTex_ST]
Float 112 [_OutlineWidth]
Float 116 [_FaceDilate]
Float 120 [_ScaleRatioA]
ConstBuffer "UnityShadows" 416
Vector 80 [unity_LightShadowBias]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
BindCB  "$Globals" 0
BindCB  "UnityShadows" 1
BindCB  "UnityPerDraw" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyz 
// NORMAL                   0   xyz         1     NONE   float       
// TEXCOORD                 0   xyzw        2     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 1   xy          1     NONE   float   xy  
// TEXCOORD                 2     z         1     NONE   float     z 
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c1         cb0             6         2  ( FLT, FLT, FLT, FLT)
// c3         cb1             5         1  ( FLT, FLT, FLT, FLT)
// c4         cb2             0         4  ( FLT, FLT, FLT, FLT)
//
//
// Runtime generated constant mappings:
//
// Target Reg                               Constant Description
// ---------- --------------------------------------------------
// c0                              Vertex Shader position offset
//
//
// Level9 shader bytecode:
//
    vs_2_0
          def c8, 0, 1, 0.5, 0
          dcl_texcoord v0
          dcl_texcoord2 v2
   0:     mul r0, v0.y, c5
   1:     mad r0, c4, v0.x, r0
   2:     mad r0, c6, v0.z, r0
   3:     add r0, r0, c7
   4:     rcp r1.x, r0.w
   5:     mul r1.x, r1.x, c3.x
   6:     max r1.x, r1.x, c8.x
   7:     min r1.x, r1.x, c8.y
   8:     add r0.z, r0.z, r1.x
   9:     max r1.x, r0.z, c8.x
  10:     add r1.x, -r0.z, r1.x
  11:     mad oPos.z, c3.y, r1.x, r0.z
  12:     mad oT0.xy, v2, c1, c1.zwzw
  13:     mov r1.y, c8.y
  14:     mad r0.z, c2.x, -c2.z, r1.y
  15:     mad r0.z, c2.y, -c2.z, r0.z
  16:     mul oT0.z, r0.z, c8.z
  17:     mad oPos.xy, r0.w, c0, r0
  18:     mov oPos.w, r0.w

// approximately 19 instruction slots used
      vs_4_0
      dcl_constantbuffer cb0[8], immediateIndexed
      dcl_constantbuffer cb1[6], immediateIndexed
      dcl_constantbuffer cb2[4], immediateIndexed
      dcl_input v0.xyz
      dcl_input v2.xy
      dcl_output_siv o0.xyzw, position
      dcl_output o1.xy
      dcl_output o1.z
      dcl_temps 2
   0: mul r0.xyzw, v0.yyyy, cb2[1].xyzw
   1: mad r0.xyzw, cb2[0].xyzw, v0.xxxx, r0.xyzw
   2: mad r0.xyzw, cb2[2].xyzw, v0.zzzz, r0.xyzw
   3: add r0.xyzw, r0.xyzw, cb2[3].xyzw
   4: div_sat r1.x, cb1[5].x, r0.w
   5: add r0.z, r0.z, r1.x
   6: mov o0.xyw, r0.xyxw
   7: max r0.x, r0.z, l(0.000000)
   8: add r0.x, -r0.z, r0.x
   9: mad o0.z, cb1[5].y, r0.x, r0.z
  10: mad r0.x, -cb0[7].x, cb0[7].z, l(1.000000)
  11: mad r0.x, -cb0[7].y, cb0[7].z, r0.x
  12: mul o1.z, r0.x, l(0.500000)
  13: mad o1.xy, v2.xyxx, cb0[6].xyxx, cb0[6].zwzz
  14: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
// Stats: 6 math, 2 textures, 1 branches
Keywords { "SHADOWS_CUBE" }
"#version 120

#ifdef VERTEX
uniform vec4 _LightPositionRange;

uniform mat4 _Object2World;
uniform vec4 _MainTex_ST;
uniform float _OutlineWidth;
uniform float _FaceDilate;
uniform float _ScaleRatioA;
varying vec3 xlv_TEXCOORD0;
varying vec2 xlv_TEXCOORD1;
varying float xlv_TEXCOORD2;
void main ()
{
  xlv_TEXCOORD0 = ((_Object2World * gl_Vertex).xyz - _LightPositionRange.xyz);
  gl_Position = (gl_ModelViewProjectionMatrix * gl_Vertex);
  xlv_TEXCOORD1 = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  xlv_TEXCOORD2 = (((1.0 - 
    (_OutlineWidth * _ScaleRatioA)
  ) - (_FaceDilate * _ScaleRatioA)) / 2.0);
}


#endif
#ifdef FRAGMENT
uniform vec4 _LightPositionRange;
uniform vec4 unity_LightShadowBias;
uniform sampler2D _MainTex;
varying vec3 xlv_TEXCOORD0;
varying vec2 xlv_TEXCOORD1;
varying float xlv_TEXCOORD2;
void main ()
{
  float x_1;
  x_1 = (texture2D (_MainTex, xlv_TEXCOORD1).w - xlv_TEXCOORD2);
  if ((x_1 < 0.0)) {
    discard;
  };
  gl_FragData[0] = vec4(((sqrt(
    dot (xlv_TEXCOORD0, xlv_TEXCOORD0)
  ) + unity_LightShadowBias.x) * _LightPositionRange.w));
}


#endif
"
}
SubProgram "d3d9 " {
// Stats: 14 math
Keywords { "SHADOWS_CUBE" }
Bind "vertex" Vertex
Bind "texcoord" TexCoord0
Matrix 4 [_Object2World] 3
Matrix 0 [glstate_matrix_mvp]
Float 10 [_FaceDilate]
Vector 7 [_LightPositionRange]
Vector 8 [_MainTex_ST]
Float 9 [_OutlineWidth]
Float 11 [_ScaleRatioA]
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float _FaceDilate;
//   float4 _LightPositionRange;
//   float4 _MainTex_ST;
//   row_major float4x4 _Object2World;
//   float _OutlineWidth;
//   float _ScaleRatioA;
//   row_major float4x4 glstate_matrix_mvp;
//
//
// Registers:
//
//   Name                Reg   Size
//   ------------------- ----- ----
//   glstate_matrix_mvp  c0       4
//   _Object2World       c4       3
//   _LightPositionRange c7       1
//   _MainTex_ST         c8       1
//   _OutlineWidth       c9       1
//   _FaceDilate         c10      1
//   _ScaleRatioA        c11      1
//

    vs_2_0
    def c12, 1, 0.5, 0, 0
    dcl_position v0
    dcl_texcoord v1
    dp4 r0.x, c4, v0
    dp4 r0.y, c5, v0
    dp4 r0.z, c6, v0
    add oT0.xyz, r0, -c7
    dp4 oPos.x, c0, v0
    dp4 oPos.y, c1, v0
    dp4 oPos.z, c2, v0
    dp4 oPos.w, c3, v0
    mad oT1.xy, v1, c8, c8.zwzw
    mov r0.x, c11.x
    mov r1.x, c12.x
    mad r0.y, c9.x, -r0.x, r1.x
    mad r0.x, c10.x, -r0.x, r0.y
    mul oT2.x, r0.x, c12.y

// approximately 14 instruction slots used
"
}
SubProgram "d3d11 " {
// Stats: 13 math
Keywords { "SHADOWS_CUBE" }
Bind "vertex" Vertex
Bind "texcoord" TexCoord0
ConstBuffer "$Globals" 128
Vector 96 [_MainTex_ST]
Float 112 [_OutlineWidth]
Float 116 [_FaceDilate]
Float 120 [_ScaleRatioA]
ConstBuffer "UnityLighting" 720
Vector 16 [_LightPositionRange]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
BindCB  "$Globals" 0
BindCB  "UnityLighting" 1
BindCB  "UnityPerDraw" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// NORMAL                   0   xyz         1     NONE   float       
// TEXCOORD                 0   xyzw        2     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xyz         0     NONE   float   xyz 
// SV_POSITION              0   xyzw        1      POS   float   xyzw
// TEXCOORD                 1   xy          2     NONE   float   xy  
// TEXCOORD                 2     z         2     NONE   float     z 
//
      vs_4_0
      dcl_constantbuffer cb0[8], immediateIndexed
      dcl_constantbuffer cb1[2], immediateIndexed
      dcl_constantbuffer cb2[16], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v2.xy
      dcl_output o0.xyz
      dcl_output_siv o1.xyzw, position
      dcl_output o2.xy
      dcl_output o2.z
      dcl_temps 1
   0: mul r0.xyz, v0.yyyy, cb2[13].xyzx
   1: mad r0.xyz, cb2[12].xyzx, v0.xxxx, r0.xyzx
   2: mad r0.xyz, cb2[14].xyzx, v0.zzzz, r0.xyzx
   3: mad r0.xyz, cb2[15].xyzx, v0.wwww, r0.xyzx
   4: add o0.xyz, r0.xyzx, -cb1[1].xyzx
   5: mul r0.xyzw, v0.yyyy, cb2[1].xyzw
   6: mad r0.xyzw, cb2[0].xyzw, v0.xxxx, r0.xyzw
   7: mad r0.xyzw, cb2[2].xyzw, v0.zzzz, r0.xyzw
   8: mad o1.xyzw, cb2[3].xyzw, v0.wwww, r0.xyzw
   9: mad r0.x, -cb0[7].x, cb0[7].z, l(1.000000)
  10: mad r0.x, -cb0[7].y, cb0[7].z, r0.x
  11: mul o2.z, r0.x, l(0.500000)
  12: mad o2.xy, v2.xyxx, cb0[6].xyxx, cb0[6].zwzz
  13: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "d3d11_9x " {
// Stats: 13 math
Keywords { "SHADOWS_CUBE" }
Bind "vertex" Vertex
Bind "texcoord" TexCoord0
ConstBuffer "$Globals" 128
Vector 96 [_MainTex_ST]
Float 112 [_OutlineWidth]
Float 116 [_FaceDilate]
Float 120 [_ScaleRatioA]
ConstBuffer "UnityLighting" 720
Vector 16 [_LightPositionRange]
ConstBuffer "UnityPerDraw" 352
Matrix 0 [glstate_matrix_mvp]
Matrix 192 [_Object2World]
BindCB  "$Globals" 0
BindCB  "UnityLighting" 1
BindCB  "UnityPerDraw" 2
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// NORMAL                   0   xyz         1     NONE   float       
// TEXCOORD                 0   xyzw        2     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xyz         0     NONE   float   xyz 
// SV_POSITION              0   xyzw        1      POS   float   xyzw
// TEXCOORD                 1   xy          2     NONE   float   xy  
// TEXCOORD                 2     z         2     NONE   float     z 
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c1         cb0             6         2  ( FLT, FLT, FLT, FLT)
// c3         cb1             1         1  ( FLT, FLT, FLT, FLT)
// c4         cb2             0         4  ( FLT, FLT, FLT, FLT)
// c8         cb2            12         4  ( FLT, FLT, FLT, FLT)
//
//
// Runtime generated constant mappings:
//
// Target Reg                               Constant Description
// ---------- --------------------------------------------------
// c0                              Vertex Shader position offset
//
//
// Level9 shader bytecode:
//
    vs_2_0
          def c12, 1, 0.5, 0, 0
          dcl_texcoord v0
          dcl_texcoord2 v2
   0:     mul r0.xyz, v0.y, c9
   1:     mad r0.xyz, c8, v0.x, r0
   2:     mad r0.xyz, c10, v0.z, r0
   3:     mad r0.xyz, c11, v0.w, r0
   4:     add oT0.xyz, r0, -c3
   5:     mad oT1.xy, v2, c1, c1.zwzw
   6:     mov r0.xz, c2
   7:     mad r0.x, r0.x, -r0.z, c12.x
   8:     mad r0.x, c2.y, -c2.z, r0.x
   9:     mul oT1.z, r0.x, c12.y
  10:     mul r0, v0.y, c5
  11:     mad r0, c4, v0.x, r0
  12:     mad r0, c6, v0.z, r0
  13:     mad r0, c7, v0.w, r0
  14:     mad oPos.xy, r0.w, c0, r0
  15:     mov oPos.zw, r0

// approximately 16 instruction slots used
      vs_4_0
      dcl_constantbuffer cb0[8], immediateIndexed
      dcl_constantbuffer cb1[2], immediateIndexed
      dcl_constantbuffer cb2[16], immediateIndexed
      dcl_input v0.xyzw
      dcl_input v2.xy
      dcl_output o0.xyz
      dcl_output_siv o1.xyzw, position
      dcl_output o2.xy
      dcl_output o2.z
      dcl_temps 1
   0: mul r0.xyz, v0.yyyy, cb2[13].xyzx
   1: mad r0.xyz, cb2[12].xyzx, v0.xxxx, r0.xyzx
   2: mad r0.xyz, cb2[14].xyzx, v0.zzzz, r0.xyzx
   3: mad r0.xyz, cb2[15].xyzx, v0.wwww, r0.xyzx
   4: add o0.xyz, r0.xyzx, -cb1[1].xyzx
   5: mul r0.xyzw, v0.yyyy, cb2[1].xyzw
   6: mad r0.xyzw, cb2[0].xyzw, v0.xxxx, r0.xyzw
   7: mad r0.xyzw, cb2[2].xyzw, v0.zzzz, r0.xyzw
   8: mad o1.xyzw, cb2[3].xyzw, v0.wwww, r0.xyzw
   9: mad r0.x, -cb0[7].x, cb0[7].z, l(1.000000)
  10: mad r0.x, -cb0[7].y, cb0[7].z, r0.x
  11: mul o2.z, r0.x, l(0.500000)
  12: mad o2.xy, v2.xyxx, cb0[6].xyxx, cb0[6].zwzz
  13: ret 
// Approximately 0 instruction slots used
"
}
}
Program "fp" {
SubProgram "opengl " {
Keywords { "SHADOWS_DEPTH" }
"// shader disassembly not supported on opengl"
}
SubProgram "d3d9 " {
// Stats: 4 math, 2 textures
Keywords { "SHADOWS_DEPTH" }
SetTexture 0 [_MainTex] 2D 0
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   sampler2D _MainTex;
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   _MainTex     s0       1
//

    ps_2_0
    dcl t0
    dcl t1.xy
    dcl t2.x
    dcl_2d s0
    texld_pp r0, t1, s0
    add r0, r0.w, -t2.x
    texkill r0
    rcp r0.x, t0.w
    mul r0, r0.x, t0.z
    mov oC0, r0

// approximately 6 instruction slots used (1 texture, 5 arithmetic)
"
}
SubProgram "d3d11 " {
// Stats: 2 math, 1 textures
Keywords { "SHADOWS_DEPTH" }
SetTexture 0 [_MainTex] 2D 0
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 1   xy          1     NONE   float   xy  
// TEXCOORD                 2     z         1     NONE   float     z 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
      ps_4_0
      dcl_sampler s0, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_input_ps linear v1.xy
      dcl_input_ps linear v1.z
      dcl_output o0.xyzw
      dcl_temps 1
   0: sample r0.xyzw, v1.xyxx, t0.xyzw, s0
   1: add r0.x, r0.w, -v1.z
   2: lt r0.x, r0.x, l(0.000000)
   3: discard_nz r0.x
   4: mov o0.xyzw, l(0,0,0,0)
   5: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "d3d11_9x " {
// Stats: 2 math, 1 textures
Keywords { "SHADOWS_DEPTH" }
SetTexture 0 [_MainTex] 2D 0
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 1   xy          1     NONE   float   xy  
// TEXCOORD                 2     z         1     NONE   float     z 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
          def c0, 0, 0, 0, 0
          dcl t0.xyz
          dcl_2d s0
   0:     texld_pp r0, t0, s0
   0:     add r0, r0.w, -t0.z
   1:     texkill r0
   2:     mov r0, c0.x
   3:     mov oC0, r0

// approximately 5 instruction slots used (1 texture, 4 arithmetic)
      ps_4_0
      dcl_sampler s0, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_input_ps linear v1.xy
      dcl_input_ps linear v1.z
      dcl_output o0.xyzw
      dcl_temps 1
   0: sample r0.xyzw, v1.xyxx, t0.xyzw, s0
   1: add r0.x, r0.w, -v1.z
   2: lt r0.x, r0.x, l(0.000000)
   3: discard_nz r0.x
   4: mov o0.xyzw, l(0,0,0,0)
   5: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "opengl " {
Keywords { "SHADOWS_CUBE" }
"// shader disassembly not supported on opengl"
}
SubProgram "d3d9 " {
// Stats: 7 math, 2 textures
Keywords { "SHADOWS_CUBE" }
Vector 0 [_LightPositionRange]
Vector 1 [unity_LightShadowBias]
SetTexture 0 [_MainTex] 2D 0
"//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float4 _LightPositionRange;
//   sampler2D _MainTex;
//   float4 unity_LightShadowBias;
//
//
// Registers:
//
//   Name                  Reg   Size
//   --------------------- ----- ----
//   _LightPositionRange   c0       1
//   unity_LightShadowBias c1       1
//   _MainTex              s0       1
//

    ps_2_0
    dcl t0.xyz
    dcl t1.xy
    dcl t2.x
    dcl_2d s0
    texld_pp r0, t1, s0
    add r0, r0.w, -t2.x
    texkill r0
    dp3 r0.x, t0, t0
    rsq r0.x, r0.x
    rcp r0.x, r0.x
    add r0.x, r0.x, c1.x
    mul r0, r0.x, c0.w
    mov oC0, r0

// approximately 9 instruction slots used (1 texture, 8 arithmetic)
"
}
SubProgram "d3d11 " {
// Stats: 6 math, 1 textures
Keywords { "SHADOWS_CUBE" }
SetTexture 0 [_MainTex] 2D 0
ConstBuffer "UnityLighting" 720
Vector 16 [_LightPositionRange]
ConstBuffer "UnityShadows" 416
Vector 80 [unity_LightShadowBias]
BindCB  "UnityLighting" 0
BindCB  "UnityShadows" 1
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xyz         0     NONE   float   xyz 
// SV_POSITION              0   xyzw        1      POS   float       
// TEXCOORD                 1   xy          2     NONE   float   xy  
// TEXCOORD                 2     z         2     NONE   float     z 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
      ps_4_0
      dcl_constantbuffer cb0[2], immediateIndexed
      dcl_constantbuffer cb1[6], immediateIndexed
      dcl_sampler s0, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_input_ps linear v0.xyz
      dcl_input_ps linear v2.xy
      dcl_input_ps linear v2.z
      dcl_output o0.xyzw
      dcl_temps 1
   0: sample r0.xyzw, v2.xyxx, t0.xyzw, s0
   1: add r0.x, r0.w, -v2.z
   2: lt r0.x, r0.x, l(0.000000)
   3: discard_nz r0.x
   4: dp3 r0.x, v0.xyzx, v0.xyzx
   5: sqrt r0.x, r0.x
   6: add r0.x, r0.x, cb1[5].x
   7: mul o0.xyzw, r0.xxxx, cb0[1].wwww
   8: ret 
// Approximately 0 instruction slots used
"
}
SubProgram "d3d11_9x " {
// Stats: 6 math, 1 textures
Keywords { "SHADOWS_CUBE" }
SetTexture 0 [_MainTex] 2D 0
ConstBuffer "UnityLighting" 720
Vector 16 [_LightPositionRange]
ConstBuffer "UnityShadows" 416
Vector 80 [unity_LightShadowBias]
BindCB  "UnityLighting" 0
BindCB  "UnityShadows" 1
"//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xyz         0     NONE   float   xyz 
// SV_POSITION              0   xyzw        1      POS   float       
// TEXCOORD                 1   xy          2     NONE   float   xy  
// TEXCOORD                 2     z         2     NONE   float     z 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             1         1  ( FLT, FLT, FLT, FLT)
// c1         cb1             5         1  ( FLT, FLT, FLT, FLT)
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
          dcl t0.xyz
          dcl t1.xyz
          dcl_2d s0
   0:     texld_pp r0, t1, s0
   0:     add r0, r0.w, -t1.z
   1:     texkill r0
   2:     dp3 r0.x, t0, t0
   3:     rsq r0.x, r0.x
   4:     rcp r0.x, r0.x
   5:     add r0.x, r0.x, c1.x
   6:     mul r0, r0.x, c0.w
   7:     mov oC0, r0

// approximately 9 instruction slots used (1 texture, 8 arithmetic)
      ps_4_0
      dcl_constantbuffer cb0[2], immediateIndexed
      dcl_constantbuffer cb1[6], immediateIndexed
      dcl_sampler s0, mode_default
      dcl_resource_texture2d (float,float,float,float) t0
      dcl_input_ps linear v0.xyz
      dcl_input_ps linear v2.xy
      dcl_input_ps linear v2.z
      dcl_output o0.xyzw
      dcl_temps 1
   0: sample r0.xyzw, v2.xyxx, t0.xyzw, s0
   1: add r0.x, r0.w, -v2.z
   2: lt r0.x, r0.x, l(0.000000)
   3: discard_nz r0.x
   4: dp3 r0.x, v0.xyzx, v0.xyzx
   5: sqrt r0.x, r0.x
   6: add r0.x, r0.x, cb1[5].x
   7: mul o0.xyzw, r0.xxxx, cb0[1].wwww
   8: ret 
// Approximately 0 instruction slots used
"
}
}
 }
}
}