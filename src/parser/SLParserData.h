//
//  SLParserData.h
//  ShaderLab
//
//  Created by Neil on 13/1/18.
//  Copyright © 2018 Neil. All rights reserved.
//

#ifndef __SL_PARSER_DATA_H__
#define __SL_PARSER_DATA_H__

#include <vector>
#include <string>
#include <map>

#include "SLParserTypes.h"
#include "utils/SLStringUtils.h"

namespace shaderlab
{
	std::string GetShaderParamType(ShaderParamType type);
	std::string GetTextureDimension(TextureDimension dim);
	std::string GetFogMode(FogMode mode);

	struct SLFloat {

		SLFloat() : val(0.0f) { }

		bool operator == (const SLFloat &rhs) const
		{
			return ref == rhs.ref && val == rhs.val;
		}

		bool operator != (const SLFloat &rhs) const
		{
			return !(*this == rhs);
		}

		void SetValue(float val)
		{
			this->val = val; ref.clear();
		}

		void SetRef(const char* ref)
		{
			this->ref = ref;
		}

		std::string toString()
		{
			return FormatString("Float(ref=%s,val=%f)", ref.c_str(), val);
		}

		float val;
		std::string ref;
	};

	struct SLVector4 {

		void SetValue(float x, float y, float z, float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
			this->ref.clear();
		}

		void SetValue(float x, float y, float z)
		{
			SetValue(x, y, z, 1.0f);
		}

		void SetValue(const SLFloat &x, const SLFloat &y, const SLFloat &z, const SLFloat &w)
		{
			SetValue(x.val, y.val, z.val, w.val);
		}

		void SetValue(const SLFloat &x, const SLFloat &y, const SLFloat &z)
		{
			SetValue(x.val, y.val, z.val);
		}

		void SetRef(const char* ref)
		{
			this->ref = ref;
		}

		bool operator == (const SLVector4 &rhs) const
		{
			return ref == rhs.ref && x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
		}

		bool operator != (const SLVector4 &rhs) const
		{
			return !(*this == rhs);
		}

		std::string toString()
		{
			return FormatString("Vector4(ref=%s,x=%f,y=%f,z=%f,w=%f)", ref.c_str(), x, y, z, w);
		}

		float x;
		float y;
		float z;
		float w;
		std::string ref;
	};

	struct SLStencilOperation {

		SLFloat comp;
		SLFloat pass;
		SLFloat fail;
		SLFloat zFail;

		bool operator == (const SLStencilOperation &rhs) const
		{
			return comp == rhs.comp && pass == rhs.pass && fail == rhs.fail && zFail == rhs.zFail;
		}

		bool operator != (const SLStencilOperation &rhs) const
		{
			return !(*this == rhs);
		}

		std::string toString()
		{
			return FormatString("StencilOp[comp=%s,pass=%s,fail=%s,zfail=%s]", comp.toString().c_str(), pass.toString().c_str(), fail.toString().c_str(), zFail.toString().c_str());
		}

	};


	struct SLPropTexture
	{
		SLPropTexture();
		~SLPropTexture();

		bool operator == (const SLPropTexture &rhs) const
		{
			return name == rhs.name && dimension == rhs.dimension;
		}

		bool operator != (const SLPropTexture &rhs) const
		{
			return !(*this == rhs);
		}

		std::string toString()
		{
			return FormatString("TexProp(name=%s,dim=%s)", name.c_str(), GetTextureDimension(dimension).c_str());
		}

		std::string name;
		TextureDimension dimension;
	};

	struct SLPropValue {
		enum Type {
			kColor,
			kVector,
			kFloat,
			kRange,
			kTexture,
		};

		SLPropValue(const char* name, const char* desc, SLPropValue::Type type, const std::vector<std::string> &atts);
		~SLPropValue();

		bool operator == (const SLPropValue &rhs) const;
		bool operator != (const SLPropValue &rhs) const
		{
			return !(*this == rhs);
		}

		std::string GetType(Type type)
		{
			switch (type)
			{
			case SLPropValue::kColor:
				return "Color";
				break;
			case SLPropValue::kVector:
				return "Vector";
				break;
			case SLPropValue::kFloat:
				return "Float";
				break;
			case SLPropValue::kRange:
				return "Range";
				break;
			case SLPropValue::kTexture:
				return "Texture";
				break;
			default:
				return "UnKnown";
				break;
			}
			return "UnKnown";
		}

		std::string toString()
		{
			std::string ret("Property{");
			if (attributes.size() > 0) {
				ret += "Attributes=";
				for (std::size_t i = 0; i < attributes.size(); ++i) {
					ret += attributes[i] + ",";
				}
			}
			ret += FormatString(
				"name=%s,description=%s,type=%s,value=(%f,%f,%f,%f),Texture=%s",
				name.c_str(), description.c_str(), GetType(type).c_str(),
				value[0], value[1], value[2], value[3],
				texture.toString().c_str()
			);
			return ret;
		}

		Type type;
		std::string name;
		std::string description;
		std::vector<std::string> attributes; // https://docs.unity3d.com/Manual/SL-Properties.html
		float value[4];
		SLPropTexture texture;
	};

	struct SLProperties {

		bool operator == (const SLProperties &rhs) const;
		bool operator != (const SLProperties &rhs) const { return !(*this == rhs); }

		void AddFloatProperty(const char* name, const char* desc, const std::vector<std::string> &atts, float value);
		void AddVectorProperty(const char* name, const char* desc, const std::vector<std::string> &atts, const SLVector4 &value);
		void AddColorProperty(const char* name, const char* desc, const std::vector<std::string> &atts, const SLVector4 &value);
		void AddRangeProperty(const char* name, const char* desc, const std::vector<std::string> &atts, float val, float valmin, float valmax);
		void AddTextureProperty(const char* name, const char* desc, const std::vector<std::string> &atts, const SLPropTexture &tex);

		std::string toString()
		{
			std::string ret("Properties:\n");
			if (props.size() > 0) {
				for (std::size_t i = 0; i < props.size(); ++i) {
					ret += "    " + props[i].toString() + "\n";
				}
			}
			return ret;
		}

		std::vector<SLPropValue> props;
	};

	struct SLSubProgram {

		struct ParamVector {

			int index;
			int dimension;
			int arraySize;
			std::string name;
			ShaderParamType type;

			ParamVector(ShaderParamType type, const std::string &name, int index, int dimension, int arraySize)
			: type(type)
			, name(name)
			, index(index)
			, dimension(dimension)
			, arraySize(arraySize)
			{

			}

			bool operator == (const ParamVector &rhs) const
			{
				return type == rhs.type && name == rhs.name && index == rhs.index && dimension == rhs.dimension && arraySize == rhs.arraySize;
			}

			bool operator != (const ParamVector &rhs) const
			{
				return !(*this == rhs);
			}

			std::string toString()
			{
				return FormatString("VectorParam(name=%s,type=%s,index=%d,dimension=%d,array=%d)", name.c_str(), GetShaderParamType(type).c_str(), index, dimension, arraySize);
			}
		};

		struct ParamMatrix {

			std::string name;
			int index;
			int rows;
			int cols;
			int arraySize;

			ParamMatrix(const std::string &name, int idx, int rows, int cols, int arraySize)
				: name(name)
				, index(idx)
				, rows(rows)
				, cols(cols)
				, arraySize(arraySize)
			{

			}

			bool operator == (const ParamMatrix &rhs) const
			{
				return name == rhs.name && index == rhs.index && rows == rhs.rows && cols == rhs.cols && arraySize == rhs.arraySize;
			}

			std::string toString()
			{
				return FormatString("MatrixParam(name=%s,index=%d,rows=%d,cols=%d,array=%d)", name.c_str(), index, rows, cols, arraySize);
			}
		};

		struct ParamTexture {

			int index;
			std::string name;
			int samplerIndex;
			TextureDimension dimension;

			ParamTexture(int idx, const std::string &name, TextureDimension dimension, int sampler)
				: index(idx)
				, name(name)
				, dimension(dimension)
				, samplerIndex(sampler)
			{

			}

			bool operator == (const ParamTexture &rhs) const
			{
				return name == rhs.name && index == rhs.index && samplerIndex == rhs.samplerIndex && dimension == rhs.dimension;
			}

			std::string toString()
			{
				return FormatString("TextureParam(name=%s,index=%d,sampler=%d,dim=%s)", name.c_str(), index, samplerIndex, GetTextureDimension(dimension).c_str());
			}
		};

		struct ConstantBuffer {

			int size;
			std::string name;
			std::vector<ParamMatrix> matrixParams;
			std::vector<ParamVector> vectorParams;

			ConstantBuffer(const std::string &name, int size)
				: name(name)
				, size(size)
			{

			}

			bool operator == (const ConstantBuffer &rhs) const
			{
				return name == rhs.name && size == rhs.size && matrixParams == rhs.matrixParams && vectorParams == rhs.vectorParams;
			}

			std::string toString()
			{
				std::string ret("ConstantBuffer[");
				for (std::size_t i = 0; i < vectorParams.size(); ++i) {
					ret += vectorParams[i].toString();
				}
				for (std::size_t i = 0; i < matrixParams.size(); ++i) {
					ret += matrixParams[i].toString();
				}
				ret += "]";
				return ret;
			}
		};

		struct BindChannel
		{
			std::string src;
			std::string dest;
			int stride;
			BindChannel(const std::string &srcChannel, const std::string &destChannel, int stride) 
			: src(srcChannel)
			, dest(destChannel)
			, stride(stride)
			{

			}

			bool operator == (const BindChannel &rhs) const
			{
				return src == rhs.src && dest == rhs.dest && stride == rhs.stride;
			}

			bool operator != (const BindChannel &rhs) const
			{
				return !(*this == rhs);
			}

			std::string toString()
			{
				return FormatString("BindChannel(src=%s,dest=%s,stride=%d)", src.c_str(), dest.c_str(), stride);
			}

		};

		struct BindBuffer {

			int index;
			std::string name;

			BindBuffer(const std::string &name, int idx) : name(name), index(idx)
			{
			}

			bool operator == (const BindBuffer &rhs) const
			{
				return name == rhs.name && index == rhs.index;
			}

			bool operator != (const BindBuffer &rhs) const
			{
				return !(*this == rhs);
			}

			std::string toString()
			{
				return FormatString("BindBuffer(name=%s,index=%d)", name.c_str(), index);
			}
		};

		SLSubProgram();
		~SLSubProgram();

		void AddParamVector(ShaderParamType type, int index, int dimension, const std::string &name, int arraySize = -1);
		void AddParamMatrix(int index, const std::string &name, int rows, int cols, int arraySize = -1);
		void AddParamTexture(int index, const char* name, TextureDimension textureDimension, int sampler);
		void AddParamTexture(const char* name, TextureDimension textureDimension)
		{
			AddParamTexture(textureParams.size(), name, textureDimension, textureParams.size());
		}

		void AddParamBuffer(int index, const char* name);
		void SetKeywords(const std::vector<std::string> &keywords);
		void SetConstBuffer(const char* name, int usedSize);
		void BindConstBuffer(const char* name, int bindIndex);

		bool operator != (const SLSubProgram &rhs) const
		{
			return !(*this == rhs);
		}
		bool operator == (const SLSubProgram& r) const;

		void Bind(const char* src, const char* dest, int stride = 4);

		std::string toString()
		{
			std::string ret("SLSubProgram:\n");
			ret += "    name:" + name + "\n";

			if (bindChannels.size() > 0) {
				ret += "    BindChannel:\n        ";
				for (std::size_t i = 0; i < bindChannels.size(); ++i) {
					ret += bindChannels[i].toString() + "\n        ";
				}
				ret += "\n";
			}

			if (keywords.size() > 0) {
				ret += "    Keywords:";
				for (std::size_t i = 0; i < keywords.size(); ++i) {
					ret += keywords[i] + " ";
				}
				ret += "\n\n";
			}

			if (vectorParams.size() > 0) {
				ret += "    VectorParams:\n        ";
				for (std::size_t i = 0; i < vectorParams.size(); ++i) {
					ret += vectorParams[i].toString() + "\n        ";
				}
				ret += "\n";
			}

			if (matrixParams.size() > 0) {
				ret += "    MatrixParams:\n        ";
				for (std::size_t i = 0; i < matrixParams.size(); ++i) {
					ret += matrixParams[i].toString() + "\n        ";
				}
				ret += "\n";
			}

			if (textureParams.size() > 0) {
				ret += "    TextureParams:\n        ";
				for (std::size_t i = 0; i < textureParams.size(); ++i) {
					ret += textureParams[i].toString() + "\n        ";
				}
				ret += "\n";
			}

			if (bufferParams.size() > 0) {
				ret += "    BufferBindParams:\n    ";
				for (std::size_t i = 0; i < bufferParams.size(); ++i) {
					ret += bufferParams[i].toString() + "\n        ";
				}
				ret += "\n";
			}

			if (constantBuffers.size() > 0) {
				ret += "    ConstBufferParams:\n        ";
				for (std::size_t i = 0; i < constantBuffers.size(); ++i) {
					ret += constantBuffers[i].toString() + "\n        ";
				}
				ret += "\n";
			}

			if (constantBufferBindings.size() > 0) {
				ret += "    ConstBufferBindParams:\n        ";
				for (std::size_t i = 0; i < constantBufferBindings.size(); ++i) {
					ret += constantBufferBindings[i].toString() + "\n        ";
				}
				ret += "\n";
			}

			return ret;
		}

		std::string	name;
		std::string	source;
		std::vector<ParamVector> vectorParams;
		std::vector<ParamMatrix> matrixParams;
		std::vector<ParamTexture> textureParams;
		std::vector<BindBuffer> bufferParams;
		std::vector<ConstantBuffer> constantBuffers;
		std::vector<BindBuffer> constantBufferBindings;
		std::vector<std::string> keywords;
		std::vector<BindChannel> bindChannels;
	};

	struct SLProgram {
		SLProgram();
		~SLProgram();

		bool operator == (const SLProgram &rhs) const;
		bool operator != (const SLProgram &rhs) const { return !(*this == rhs); }

		std::string toString()
		{
			std::string ret("Program:\n");
			ret += "    type:" + type + "\n";

			if (subPrograms.size() > 0) {
				for (std::size_t i = 0; i < subPrograms.size(); i++) {
					ret += subPrograms[i]->toString() + "\n    ";
				}
				ret += "\n";
			}

			return ret;
		}

		std::string type;
		std::vector<SLSubProgram*> subPrograms;
	};

	struct SLShaderState {
		bool operator == (const SLShaderState &rhs) const
		{
			if (name != rhs.name
				|| gpuProgramID != rhs.gpuProgramID
				|| tags != rhs.tags
				|| lod != rhs.lod
				|| zTest != rhs.zTest
				|| culling != rhs.culling
				|| zWrite != rhs.zWrite
				|| alphaToMask != rhs.alphaToMask
				|| colMask != rhs.colMask
				|| fogMode != rhs.fogMode
				|| fogStart != rhs.fogStart
				|| fogEnd != rhs.fogEnd
				|| fogDensity != rhs.fogDensity
				|| fogColor != rhs.fogColor
				|| srcBlend != rhs.srcBlend
				|| destBlend != rhs.destBlend
				|| srcBlendAlpha != rhs.srcBlendAlpha
				|| destBlendAlpha != rhs.destBlendAlpha
				|| blendOp != rhs.blendOp
				|| blendOpAlpha != rhs.blendOpAlpha
				|| stencilRef != rhs.stencilRef
				|| stencilOp != rhs.stencilOp
				|| stencilOpFront != rhs.stencilOpFront
				|| stencilOpBack != rhs.stencilOpBack
				|| stencilReadMask != rhs.stencilReadMask
				|| stencilWriteMask != rhs.stencilWriteMask
				|| offsetFactor != rhs.offsetFactor
				|| offsetUnits != rhs.offsetUnits
				) {
				return false;
			}

			return true;
		}

		bool operator != (const SLShaderState &rhs) const
		{
			return !(*this == rhs);
		};

		void AddTags(const std::map<std::string, std::string> &tagsMap)
		{
			tags.insert(tagsMap.begin(), tagsMap.end());
		}

		std::string toString()
		{
			std::string ret("State:\n");
			ret += FormatString("%-24s:%s\n", "    Name", name.c_str());
			ret += FormatString("%-24s:%d\n", "    Lod", lod);
			ret += FormatString("%-24s:%d\n", "    ProgramID", gpuProgramID);
			ret += "Fog:\n";
			ret += FormatString("%-24s:%s\n", "    FogMode", GetFogMode(fogMode).c_str());
			ret += FormatString("%-24s:%s\n", "    FogStart", fogStart.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    FogEnd", fogEnd.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    FogDensity", fogDensity.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    FogColor", fogColor.toString().c_str());
			ret += "Offset:\n";
			ret += FormatString("%-24s:%s\n", "    OffsetFactor", offsetFactor.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    OffsetUnits", offsetUnits.toString().c_str());
			ret += "Mask:\n";
			ret += FormatString("%-24s:%s\n", "    ColorMask", colMask.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    AlphaToMask", alphaToMask.toString().c_str());
			ret += "ZWrite:\n";
			ret += FormatString("%-24s:%s\n", "    ZTest", zTest.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    ZWrite", zWrite.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    Cull", culling.toString().c_str());
			ret += "Blend:\n";
			ret += FormatString("%-24s:%s\n", "    BlendOp", blendOp.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    BlendOpAlpha", blendOpAlpha.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    SrcBlend", srcBlend.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    DestBlend", destBlend.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    SrcBlendAlpha", srcBlendAlpha.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    DestBlendAlpha", destBlendAlpha.toString().c_str());
			ret += "Stencil:\n";
			ret += FormatString("%-24s:%s\n", "    StencilRef", stencilRef.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    StencilReadMask", stencilReadMask.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    StencilWriteMask", stencilWriteMask.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    StencilOp", stencilOp.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    StencilOpFront", stencilOpFront.toString().c_str());
			ret += FormatString("%-24s:%s\n", "    StencilOpBack", stencilOpBack.toString().c_str());
			return ret;
		}

		int	lod;
		int gpuProgramID;
		std::string name;
		std::map<std::string, std::string> tags;

		FogMode	fogMode;
		SLFloat fogStart;
		SLFloat fogEnd;
		SLFloat fogDensity;
		SLVector4 fogColor;
		SLFloat colMask;
		SLFloat alphaToMask;
		SLFloat offsetFactor;
		SLFloat offsetUnits;
		SLFloat zTest;
		SLFloat zWrite;
		SLFloat culling;
		SLFloat blendOp;
		SLFloat blendOpAlpha;
		SLFloat srcBlend;
		SLFloat destBlend;
		SLFloat srcBlendAlpha;
		SLFloat destBlendAlpha;
		SLFloat stencilRef;
		SLFloat stencilReadMask;
		SLFloat stencilWriteMask;
		SLStencilOperation stencilOp;
		SLStencilOperation stencilOpFront;
		SLStencilOperation stencilOpBack;
	};

	struct SLPassBase {

		enum PassType {
			kPassNormal,
			kPassUse,
			kPassGrab,
		};

		SLPassBase(PassType type) : type(type)
		{

		}

		virtual ~SLPassBase()
		{

		}

		virtual std::string toString()
		{
			return "BasePass";
		}

		PassType type;
	};

	struct SLNormalPass : public SLPassBase {

		SLNormalPass(const SLShaderState &state);
		virtual ~SLNormalPass();

		bool operator == (const SLNormalPass &rhs) const;
		bool operator != (const SLNormalPass &rhs) const
		{
			return !(*this == rhs);
		}

		virtual std::string toString() override
		{
			std::string ret("Pass:\n");
			ret += FormatString("%-24s:%s\n", "    Type", "Pass");
			if (programs.size() > 0) {
				ret += "State:\n";
				ret += state.toString() + "\n";
				for (std::size_t i = 0; i < programs.size(); ++i) {
					ret += programs[i]->toString();
				}
			}
			return ret;
		}

		SLShaderState state;
		std::vector<SLProgram*> programs;
	};

	struct SLUsePass : public SLPassBase {

		SLUsePass(const char* name)
			: SLPassBase(kPassUse)
			, useName(name)
		{

		}

		bool operator == (const SLUsePass &rhs) const
		{
			return useName == rhs.useName;
		}
		bool operator != (const SLUsePass &rhs) const
		{
			return !(*this == rhs);
		}

		virtual std::string toString() override
		{
			std::string ret("Pass:\n");
			ret += FormatString("%-24s:%s\n", "    Type", "UsePass");
			ret += FormatString("%-24s:%s\n", "    UseName", useName.c_str());
			return ret;
		}

		std::string useName;
	};

	struct SLGrabPass : public SLPassBase {
		SLGrabPass();
		~SLGrabPass();

		bool operator == (const SLGrabPass &rhs) const
		{
			return
				name == rhs.name && textureName == rhs.textureName && tags == rhs.tags;
		}

		bool operator != (const SLGrabPass &rhs) const
		{
			return !(*this == rhs);
		}

		void AddTags(const std::map<std::string, std::string> &tags);

		virtual std::string toString() override
		{
			std::string ret("Pass:\n");
			ret += FormatString("%-24s:%s\n", "    Type", "UsePass");
			ret += FormatString("%-24s:%s\n", "    Name", name.c_str());
			ret += FormatString("%-24s:%s\n", "    TexName", textureName.c_str());
			if (tags.size() > 0) {
				for (auto it = tags.begin(); it != tags.end(); ++it) {
					ret += FormatString("%-24s:%s > %s\n", "    Tags", it->first.c_str(), it->second.c_str());
				}
			}
			return ret;
		}

		std::string		name;
		std::string		textureName;
		std::map<std::string, std::string>	tags;
	};

	struct SLSubShader {

		SLSubShader();
		~SLSubShader();

		void SetPasses(std::vector<SLPassBase*> *passarray);
		bool operator == (const SLSubShader &rhs) const;
		bool operator != (const SLSubShader &rhs) const
		{
			return !(*this == rhs);
		}

		std::string toString()
		{
			std::string ret("SubShader:\n");
			ret += FormatString("%-24s:%d\n", "    Lod", lod);
			if (tags.size() > 0) {
				for (auto it = tags.begin(); it != tags.end(); ++it) {
					ret += FormatString("%-24s:%s > %s\n", "    Tags", it->first.c_str(), it->second.c_str());
				}
			}
			if (passes.size() > 0) {
				ret += "Pass:\n";
				for (std::size_t i = 0; i < passes.size(); ++i) {
					ret += passes[i]->toString() + "\n";
				}
			}
			return ret;
		}

		int	lod;
		std::vector<SLPassBase*> passes;
		std::map<std::string, std::string> tags;
	};

	struct SLShader {
		SLShader();
		~SLShader();

		bool operator == (const SLShader &rhs) const;
		bool operator != (const SLShader &rhs) const
		{
			return !(*this == rhs);
		}

		std::string toString()
		{
			std::string ret("Shader:\n");
			ret += "    name:" + shaderName + "\n";
			ret += "    Fallback:" + fallbackName + "\n";
			ret += properties.toString() + "\n";
			if (subShaders.size() > 0) {
				for (std::size_t i = 0; i < subShaders.size(); ++i) {
					ret += subShaders[i]->toString();
				}
			}
			return ret;
		}

		SLProperties properties;
		std::string	fallbackName;
		std::string shaderName;
		std::vector<SLSubShader*> subShaders;
	};
}
#endif
