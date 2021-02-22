#pragma once

#include <vector>
#include <string>
#include <map>

#include "Common/Common.h"
#include "SLParserTypes.h"

namespace shaderlab
{
	struct SLFloat 
	{
		SLFloat() 
			: val(0.0f) 
		{

		}

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
			ref.clear();
			this->val = val;
		}

		void SetRef(const char* ref)
		{
			this->ref = ref;
		}

		float			val;
		std::string		ref;
	};

	struct SLVector4 
	{
		SLVector4()
			: x(0.0f)
			, y(0.0f)
			, z(0.0f)
			, w(0.0f)
		{

		}

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

		float			x;
		float			y;
		float			z;
		float			w;
		std::string		ref;
	};

	struct SLStencilOperation 
	{
		bool operator == (const SLStencilOperation &rhs) const
		{
			return comp == rhs.comp && pass == rhs.pass && fail == rhs.fail && zFail == rhs.zFail;
		}

		bool operator != (const SLStencilOperation &rhs) const
		{
			return !(*this == rhs);
		}

		SLFloat			comp;
		SLFloat			pass;
		SLFloat			fail;
		SLFloat			zFail;
	};

	struct SLPropTexture
	{
		SLPropTexture()
			: dimension(kTexDimUnknown)
		{

		}

		bool operator == (const SLPropTexture &rhs) const
		{
			return name == rhs.name && dimension == rhs.dimension;
		}

		bool operator != (const SLPropTexture &rhs) const
		{
			return !(*this == rhs);
		}

		TextureDimension	dimension;
		std::string			name;
	};

	struct SLPropValue 
	{
		enum Type 
		{
			kColor,
			kVector,
			kFloat,
			kRange,
			kTexture,
		};

		SLPropValue(const char* inName, const char* desc, SLPropValue::Type inType, const std::vector<std::string>& atts)
			: type(inType)
			, name(inName)
			, description(desc)
			, attributes(atts)
		{
			for (int32 i = 0; i < 4; ++i)
			{
				value[i] = 0.0f;
			}
		}

		bool operator == (const SLPropValue& rhs) const
		{
			if (name != rhs.name || 
				description != rhs.description || 
				type != rhs.type || 
				texture != rhs.texture
			) 
			{
				return false;
			}

			if (attributes.size() != rhs.attributes.size())
			{
				return false;
			}

			for (int32 i = 0; i < attributes.size(); ++i)
			{
				if (attributes[i] != rhs.attributes[i])
				{
					return false;
				}
			}

			for (int32 i = 0; i < 4; ++i) 
			{
				if (value[i] != rhs.value[i]) 
				{
					return false;
				}
			}

			return true;
		}

		bool operator != (const SLPropValue &rhs) const
		{
			return !(*this == rhs);
		}

		Type						type;
		std::string					name;
		std::string					description;
		std::vector<std::string>	attributes;
		float						value[4];
		SLPropTexture				texture;
	};

	struct SLProperties 
	{
		bool operator == (const SLProperties& rhs) const
		{
			if (props.size() != rhs.props.size()) 
			{
				return false;
			}

			for (int32 i = 0; i < props.size(); ++i) 
			{
				if (props[i] != rhs.props[i]) 
				{
					return false;
				}
			}

			return true;
		}

		bool operator != (const SLProperties &rhs) const 
		{ 
			return !(*this == rhs); 
		}

		void AddFloatProperty(const char* name, const char* desc, const std::vector<std::string>& atts, float value)
		{
			props.emplace_back(name, desc, SLPropValue::kFloat, atts);
			props.back().value[0] = value;
		}

		void AddVectorProperty(const char* name, const char* desc, const std::vector<std::string>& atts, const SLVector4& value)
		{
			props.emplace_back(name, desc, SLPropValue::kVector, atts);
			props.back().value[0] = value.x;
			props.back().value[1] = value.y;
			props.back().value[2] = value.z;
			props.back().value[3] = value.w;
		}

		void AddColorProperty(const char* name, const char* desc, const std::vector<std::string>& atts, const SLVector4& value)
		{
			props.emplace_back(name, desc, SLPropValue::kColor, atts);
			props.back().value[0] = value.x;
			props.back().value[1] = value.y;
			props.back().value[2] = value.z;
			props.back().value[3] = value.w;
		}

		void AddRangeProperty(const char* name, const char* desc, const std::vector<std::string>& atts, float value, float valmin, float valmax)
		{
			props.emplace_back(name, desc, SLPropValue::kRange, atts);
			props.back().value[0] = value;
			props.back().value[1] = valmin;
			props.back().value[2] = valmax;
		}

		void AddTextureProperty(const char* name, const char* desc, const std::vector<std::string>& atts, const SLPropTexture& texture)
		{
			props.emplace_back(name, desc, SLPropValue::kTexture, atts);
			props.back().texture = texture;
		}

		std::vector<SLPropValue>	props;
	};

	struct SLShaderState 
	{
		SLShaderState()
			: lod(0)
		{

		}

		bool operator == (const SLShaderState &rhs) const
		{
			if (name != rhs.name || 
				tags != rhs.tags || 
				lod != rhs.lod || 
				zTest != rhs.zTest || 
				culling != rhs.culling || 
				zWrite != rhs.zWrite || 
				alphaToMask != rhs.alphaToMask || 
				colMask != rhs.colMask ||
				srcBlend != rhs.srcBlend || 
				destBlend != rhs.destBlend || 
				srcBlendAlpha != rhs.srcBlendAlpha || 
				destBlendAlpha != rhs.destBlendAlpha || 
				blendOp != rhs.blendOp || 
				blendOpAlpha != rhs.blendOpAlpha || 
				stencilRef != rhs.stencilRef || 
				stencilOp != rhs.stencilOp || 
				stencilOpFront != rhs.stencilOpFront || 
				stencilOpBack != rhs.stencilOpBack || 
				stencilReadMask != rhs.stencilReadMask || 
				stencilWriteMask != rhs.stencilWriteMask || 
				offsetFactor != rhs.offsetFactor || 
				offsetUnits != rhs.offsetUnits
			) 
			{
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

		int32								lod;
		std::string							name;
		std::map<std::string, std::string>	tags;

		SLFloat								colMask;
		SLFloat								alphaToMask;
		SLFloat								offsetFactor;
		SLFloat								offsetUnits;
		SLFloat								zTest;
		SLFloat								zWrite;
		SLFloat								culling;
		SLFloat								blendOp;
		SLFloat								blendOpAlpha;
		SLFloat								srcBlend;
		SLFloat								destBlend;
		SLFloat								srcBlendAlpha;
		SLFloat								destBlendAlpha;
		SLFloat								stencilRef;
		SLFloat								stencilReadMask;
		SLFloat								stencilWriteMask;
		SLStencilOperation					stencilOp;
		SLStencilOperation					stencilOpFront;
		SLStencilOperation					stencilOpBack;
	};

	struct SLPassBase 
	{
		enum PassType 
		{
			kPassNormal,
			kPassUse,
			kPassCompiled,
		};

		SLPassBase(PassType inType) 
			: type(inType)
		{

		}

		virtual ~SLPassBase()
		{

		}

		PassType		type;
	};

	struct SLProgram
	{
		SLProgram()
			: type(kCG)
			, lineNo(0)
		{

		}

		bool operator == (const SLProgram& rhs) const
		{
			return type == rhs.type && source == rhs.source;
		}

		bool operator != (const SLProgram& rhs) const
		{
			return !(*this == rhs);
		}

		ProgramType		type;
		int32			lineNo;
		std::string		source;
	};

	struct SLNormalPass : public SLPassBase 
	{
		SLNormalPass(const SLShaderState& inState)
			: SLPassBase(kPassNormal)
			, state(inState)
		{

		}

		virtual ~SLNormalPass()
		{

		}

		bool operator == (const SLNormalPass& rhs) const
		{
			return state != rhs.state && program == rhs.program;
		}

		bool operator != (const SLNormalPass &rhs) const
		{
			return !(*this == rhs);
		}

		SLShaderState	state;
		SLProgram		program;
	};

	struct SLUsePass : public SLPassBase 
	{
		SLUsePass(const char* name)
			: SLPassBase(kPassUse)
			, useName(name)
		{

		}

		virtual ~SLUsePass()
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

		std::string		useName;
	};

	struct SLCompiledProgram
	{
		ShaderStage						stage;
		ShaderTarget					shaderTarget;
		std::string						entryPoint;
		std::vector<uint8>				data;
		std::vector<std::string>		keywords;
	};

	struct SLCompiledPass : public SLPassBase
	{
		SLCompiledPass()
			: SLPassBase(kPassCompiled)
		{

		}

		virtual ~SLCompiledPass()
		{
			for (int32 i = 0; i < programs.size(); ++i)
			{
				delete programs[i];
			}
			programs.clear();
		}

		SLShaderState					state;
		std::string						errorMsg;
		std::vector<SLCompiledProgram*>	programs;
	};

	struct SLSubShader
	{
		SLSubShader()
			: lod(0)
		{

		}

		~SLSubShader()
		{
			for (int32 i = 0; i < passes.size(); ++i)
			{
				delete passes[i];
			}
			passes.clear();
		}

		void SetPasses(std::vector<SLPassBase*>* passarray)
		{
			passes = *passarray;
		}

		bool operator == (const SLSubShader &rhs) const
		{
			if (tags != rhs.tags || passes.size() != rhs.passes.size() || lod != rhs.lod) 
			{
				return false;
			}

			for (int32 i = 0; i < passes.size(); ++i) 
			{
				SLPassBase* lp = passes[i];
				SLPassBase* rp = rhs.passes[i];

				if (lp->type != rp->type) 
				{
					return false;
				}

				switch (lp->type) 
				{
					case SLPassBase::kPassNormal:
					{
						if (*(static_cast<SLNormalPass*>(lp)) != *(static_cast<SLNormalPass*>(rp))) 
						{
							return false;
						}
						break;
					}
					case SLPassBase::kPassUse:
					{
						if (*(static_cast<SLUsePass*>(lp)) != *(static_cast<SLUsePass*>(rp))) 
						{
							return false;
						}
						break;
					}
				}
			}
			return true;
		}
		
		bool operator != (const SLSubShader &rhs) const
		{
			return !(*this == rhs);
		}

		int32								lod;
		std::map<std::string, std::string> 	tags;
		std::vector<SLPassBase*>			passes;
	};

	struct SLShader 
	{
		~SLShader()
		{
			for (int32 i = 0; i < subShaders.size(); ++i)
			{
				delete subShaders[i];
			}
			subShaders.clear();
		}
		
		std::string					shaderName;
		std::string					fallbackName;
		SLProperties				properties;
		std::vector<SLSubShader*>	subShaders;
	};
}