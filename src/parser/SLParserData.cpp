//
//  SLParserData.cpp
//  ShaderLab
//
//  Created by Neil on 14/1/18.
//  Copyright © 2018 Neil. All rights reserved.
//

#include <stdio.h>
#include "SLParserData.h"

namespace shaderlab
{
	std::string GetShaderParamType(ShaderParamType type)
	{
		switch (type)
		{
		case kShaderParamFloat:
			return "Float";
			break;
		case kShaderParamInt:
			return "Int";
			break;
		case kShaderParamBool:
			return "Bool";
			break;
		default:
			return "None";
			break;
		}
		return "None";
	}

	std::string GetTextureDimension(TextureDimension dim)
	{
		switch (dim)
		{
		case kTexDim2D:
			return "2D";
			break;
		case kTexDim3D:
			return "3D";
			break;
		case kTexDimCUBE:
			return "Cube";
			break;
		default:
			return "UnKnown";
			break;
		}
		return "UnKnown";
	}

	std::string GetFogMode(FogMode mode)
	{
		switch (mode)
		{
		case kFogDisabled:
			return "Off";
			break;
		case kFogLinear:
			return "Linear";
			break;
		case kFogExp:
			return "Exp";
			break;
		case kFogExp2:
			return "Exp2";
			break;
		default:
			return "UnKnown";
			break;
		}
		return "UnKnown";
	}

	SLSubProgram::SLSubProgram()
	{

	}

	SLSubProgram::~SLSubProgram()
	{

	}

	void SLSubProgram::AddParamBuffer(int index, const char* name)
	{
		bufferParams.emplace_back(name, index);
	}

	bool SLSubProgram::operator == (const SLSubProgram &rhs) const
	{
		if (source != rhs.source
			|| keywords != rhs.keywords
			|| vectorParams != rhs.vectorParams
			|| matrixParams != rhs.matrixParams
			|| textureParams != rhs.textureParams
			|| constantBuffers != rhs.constantBuffers
			|| constantBufferBindings != rhs.constantBufferBindings
			|| bufferParams != rhs.bufferParams
			)
		{
			return false;
		}
		return true;
	}

	void SLSubProgram::Bind(const char* src, const char* dest, int stride)
	{
		bindChannels.emplace_back(src, dest, stride);
	}

	void SLSubProgram::SetKeywords(const std::vector<std::string> &values)
	{
		keywords.clear();
		for (std::size_t i = 0; i < values.size(); ++i) {
			keywords.push_back(values[i]);
		}
	}

	void SLSubProgram::SetConstBuffer(const char* name, int usedSize)
	{
		constantBuffers.emplace_back(name, usedSize);
	}

	void SLSubProgram::BindConstBuffer(const char* name, int bindIndex)
	{
		constantBufferBindings.emplace_back(name, bindIndex);
	}

	void SLSubProgram::AddParamVector(ShaderParamType type, int index, int dimension, const std::string &name, int arraySize)
	{
		std::vector<ParamVector>& params = constantBuffers.empty() ? vectorParams : constantBuffers.back().vectorParams;
		params.emplace_back(type, name, index, dimension, arraySize);
	}

	void SLSubProgram::AddParamMatrix(int index, const std::string &name, int rows, int cols, int arraySize)
	{
		std::vector<ParamMatrix>& params = constantBuffers.empty() ? matrixParams : constantBuffers.back().matrixParams;
		params.emplace_back(name, index, rows, cols, arraySize);
	}

	void SLSubProgram::AddParamTexture(int index, const char* setTexture, TextureDimension textureDimension, int sampler)
	{
		textureParams.emplace_back(index, setTexture, textureDimension, sampler);
	}

	SLProgram::SLProgram()
	{

	}

	SLProgram::~SLProgram()
	{
		for (std::size_t i = 0; i < subPrograms.size(); ++i) {
			delete subPrograms[i];
		}
	}

	bool SLProgram::operator == (const SLProgram &rhs) const
	{
		if (subPrograms.size() != rhs.subPrograms.size()) {
			return false;
		}
		for (std::size_t i = 0; i < subPrograms.size(); ++i) {
			if (*(subPrograms[i]) != *(rhs.subPrograms[i])) {
				return false;
			}
		}
		return true;
	}

	SLNormalPass::SLNormalPass(const SLShaderState &state)
		: SLPassBase(kPassNormal)
		, state(state)
	{

	}

	SLNormalPass::~SLNormalPass()
	{
		for (std::size_t i = 0; i < programs.size(); ++i) {
			delete programs[i];
		}
	}

	bool SLNormalPass::operator == (const SLNormalPass &rhs) const
	{
		if (state != rhs.state || programs.size() != rhs.programs.size()) {
			return false;
		}
		for (std::size_t i = 0; i < programs.size(); ++i) {
			if (*(programs[i]) != *(rhs.programs[i])) {
				return false;
			}
		}
		return true;
	}

	SLGrabPass::SLGrabPass() : SLPassBase(kPassGrab)
	{

	}

	SLGrabPass::~SLGrabPass()
	{

	}

	void SLGrabPass::AddTags(const std::map<std::string, std::string> &value)
	{
		tags.insert(value.begin(), value.end());
	}

	SLSubShader::SLSubShader() : lod(0)
	{

	}

	SLSubShader::~SLSubShader()
	{
		for (std::size_t i = 0; i > passes.size(); ++i) {
			delete passes[i];
		}
	}

	void SLSubShader::SetPasses(std::vector<SLPassBase*> *passarray)
	{
		passes = *passarray;
	}

	bool SLSubShader::operator == (const SLSubShader &rhs) const
	{
		if (tags != rhs.tags || passes.size() != rhs.passes.size() || lod != rhs.lod) {
			return false;
		}

		for (std::size_t i = 0; i < passes.size(); ++i) {
			SLPassBase* lp = passes[i];
			SLPassBase* rp = rhs.passes[i];
			if (lp->type != rp->type) {
				return false;
			}
			switch (lp->type) {
			case SLPassBase::kPassNormal:
				if (*(static_cast<SLNormalPass*>(lp)) != *(static_cast<SLNormalPass*>(rp))) {
					return false;
				}
				break;
			case SLPassBase::kPassUse:
				if (*(static_cast<SLUsePass*>(lp)) != *(static_cast<SLUsePass*>(rp))) {
					return false;
				}
				break;
			case SLPassBase::kPassGrab:
				if (*(static_cast<SLGrabPass*>(lp)) != *(static_cast<SLGrabPass*>(rp))) {
					return false;
				}
				break;
			}
		}
		return true;
	}

	SLPropTexture::SLPropTexture() : dimension(kTexDimUnknown)
	{

	}

	SLPropTexture::~SLPropTexture()
	{

	}

	SLPropValue::SLPropValue(const char* name, const char* desc, SLPropValue::Type type, const std::vector<std::string> &atts)
		: name(name)
		, description(desc)
		, type(type)
	{
		for (std::size_t i = 0; i < atts.size(); ++i) {
			const std::string& att = atts[i];
			attributes.push_back(att);
		}
		for (int i = 0; i < 4; ++i) {
			value[i] = 0;
		}
	}

	SLPropValue::~SLPropValue()
	{

	}

	bool SLPropValue::operator == (const SLPropValue &rhs) const
	{
		if (name != rhs.name
			|| description != rhs.description
			|| type != rhs.type
			|| texture != rhs.texture
			|| attributes != rhs.attributes
			) {
			return false;
		}
		for (int i = 0; i < 4; ++i) {
			if (value[i] != rhs.value[i]) {
				return false;
			}
		}
		return true;
	}

	void SLProperties::AddFloatProperty(const char* name, const char *desc, const std::vector<std::string> &atts, float value)
	{
		props.emplace_back(name, desc, SLPropValue::kFloat, atts);
		props.back().value[0] = value;
	}

	void SLProperties::AddVectorProperty(const char* name, const char *desc, const std::vector<std::string> &atts, const SLVector4 &value)
	{
		props.emplace_back(name, desc, SLPropValue::kVector, atts);
		props.back().value[0] = value.x;
		props.back().value[1] = value.y;
		props.back().value[2] = value.z;
		props.back().value[3] = value.w;
	}

	void SLProperties::AddColorProperty(const char* name, const char *desc, const std::vector<std::string> &atts, const SLVector4 &value)
	{
		props.emplace_back(name, desc, SLPropValue::kColor, atts);
		props.back().value[0] = value.x;
		props.back().value[1] = value.y;
		props.back().value[2] = value.z;
		props.back().value[3] = value.w;
	}

	void SLProperties::AddRangeProperty(const char* name, const char *desc, const std::vector<std::string> &atts, float value, float valmin, float valmax)
	{
		props.emplace_back(name, desc, SLPropValue::kRange, atts);
		props.back().value[0] = value;
		props.back().value[1] = valmin;
		props.back().value[2] = valmax;
	}

	void SLProperties::AddTextureProperty(const char* name, const char *desc, const std::vector<std::string> &atts, const SLPropTexture &texture)
	{
		props.emplace_back(name, desc, SLPropValue::kTexture, atts);
		props.back().texture = texture;
	}

	bool SLProperties::operator == (const SLProperties &rhs) const
	{
		if (props.size() != rhs.props.size()) {
			return false;
		}
		for (std::size_t i = 0; i < props.size(); ++i) {
			if (props[i] != rhs.props[i]) {
				return false;
			}
		}
		return true;
	}

	SLShader::SLShader()
	{

	}

	SLShader::~SLShader()
	{
		for (std::size_t i = 0; i < subShaders.size(); ++i) {
			delete subShaders[i];
		}
	}

	bool SLShader::operator == (const SLShader &rhs) const
	{
		if (subShaders.size() != rhs.subShaders.size() || shaderName != rhs.shaderName || fallbackName != rhs.fallbackName || properties != rhs.properties) {
			return false;
		}
		for (std::size_t i = 0; i < subShaders.size(); ++i) {
			if (*(subShaders[i]) != *(rhs.subShaders[i])) {
				return false;
			}
		}
		return true;
	}
}