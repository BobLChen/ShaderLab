#ifndef __Shader_Types__
#define __Shader_Types__

enum TextureDimension
{
    kTexDimUnknown = 0,
	kTexDim2D,
    kTexDim3D,
    kTexDimCUBE,
    kTexDimCount
};

// https://docs.unity3d.com/Manual/SL-Blend.html
enum BlendOp
{
    kBlendOpAdd = 0,
    kBlendOpSub,
    kBlendOpRevSub,
    kBlendOpMin,
    kBlendOpMax,
    kBlendOpLogicalClear,
    kBlendOpLogicalSet,
    kBlendOpLogicalCopy,
    kBlendOpLogicalCopyInverted,
    kBlendOpLogicalNoop,
    kBlendOpLogicalInvert,
    kBlendOpLogicalAnd,
    kBlendOpLogicalNand,
    kBlendOpLogicalOr,
    kBlendOpLogicalNor,
    kBlendOpLogicalXor,
    kBlendOpLogicalEquiv,
    kBlendOpLogicalAndReverse,
    kBlendOpLogicalAndInverted,
    kBlendOpLogicalOrReverse,
    kBlendOpLogicalOrInverted,
    kBlendOpCount,
};

enum BlendMode
{
    kBlendZero = 0,
    kBlendOne,
    kBlendDstColor,
    kBlendSrcColor,
    kBlendOneMinusDstColor,
    kBlendSrcAlpha,
    kBlendOneMinusSrcColor,
    kBlendDstAlpha,
    kBlendOneMinusDstAlpha,
    kBlendSrcAlphaSaturate,
    kBlendOneMinusSrcAlpha,
    kBlendCount
};

enum CompareFunction
{
    kFuncUnknown = -1,
    kFuncDisabled = 0,
    kFuncNever,
    kFuncLess,
    kFuncEqual,
    kFuncLEqual,
    kFuncGreater,
    kFuncNotEqual,
    kFuncGEqual,
    kFuncAlways,
    kFuncCount
};

enum CullMode
{
    kCullUnknown = -1,
    kCullOff = 0,
    kCullFront,
    kCullBack,
	kCullFrontAndBack,
    kCullCount
};

enum ColorWriteMask
{	
	kColorWriteNone = 0,
    kColorWriteA = 1,
    kColorWriteB = 2,
    kColorWriteG = 4,
    kColorWriteR = 8,
    KColorWriteAll = (kColorWriteR|kColorWriteG|kColorWriteB|kColorWriteA)
};

// https://docs.unity3d.com/Manual/SL-Stencil.html
enum StencilOp
{
	kStencilOpKeep = 0,
	kStencilOpZero,
	kStencilOpReplace,
	kStencilOpIncrSat,
	kStencilOpDecrSat,
	kStencilOpInvert,
	kStencilOpIncrWrap,
	kStencilOpDecrWrap,
	kStencilOpCount
};

enum ShaderParamType
{
    kShaderParamFloat = 0,
    kShaderParamInt,
    kShaderParamBool,
    kShaderParamTypeCount
};

enum FogMode
{
    kFogUnknown = -1,
    kFogDisabled = 0,
    kFogLinear,
    kFogExp,
    kFogExp2,
    kFogModeCount
};

#endif