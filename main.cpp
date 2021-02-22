#include <stdio.h>
#include <string>
#include <cstring>

#include "Parser/SLParser.h"
#include "Compiler/SLCompiler.h"
#include "Compiler/HLSLCompiler.h"
#include "Utils/StringUtils.h"
#include "Utils/json.h"

bool ReadTextFile(const std::string &filename, std::string &output)
{
	FILE *file = fopen(filename.c_str(), "rt");
	if (!file) 
	{
		printf("file not found :%s\n", filename.c_str());
		return false;
	}

	fseek(file, 0, SEEK_END);
	int dataSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	if (dataSize <= 0) 
	{
		fclose(file);
		printf("not found data :%s\n", filename.c_str());
		return false;
	}

	output.resize(dataSize);
	int readSize = fread(&(*output.begin()), 1, dataSize, file);
	fclose(file);
	output.resize(readSize);

	return true;
}

std::string OnLoadInlcudeCallback(const char* includeName)
{
	std::string includeData;
	if (!ReadTextFile(includeName, includeData))
	{
		printf("Failed to load include file:%s\n", includeName);
	}
	return includeData;
}

struct ArgOption
{
	std::string		input;
	std::string		output;
	std::string		include;
};

void Usage() 
{
	printf("Usage: ShaderCross\n");
	printf("\n");
	printf("Main options:\n");
	printf("  -h | -?               show help.\n");
	printf("  -i                    input shaderlab file name.\n");
	printf("  -o                    output compiled shader file name.\n");
	printf("  -include              include path.\n");
}

ArgOption ParseOptions(int argc, char const *argv[])
{
	ArgOption option;

	const int argcCheck = argc - 1;

	for (int i = 1; i < argc; ++i)
	{
		if (!strcmp("-h", argv[i]) || !strcmp("-?", argv[i]))
		{
			// nothing
		}
		else if (!strcmp("-i", argv[i]) && i < argcCheck)
		{
			option.input = argv[++i];
		}
		else if (!strcmp("-o", argv[i]) && i < argcCheck) {
			option.output = argv[++i];
		}
		else if (!strcmp("-include", argv[i]) && i < argcCheck) {
			option.include = argv[++i];
		}
	}

	return option;
}

std::string ShaderToJson(const shaderlab::SLShader* shader);

int main(int argc, char const *argv[])
{
	// get options
	ArgOption option = ParseOptions(argc, argv);
	if (argc < 2 || option.input.empty())
	{
		Usage();
		return 0;
	}

	// load shaderlab text
    std::string shaderLabData;
	if (!ReadTextFile(option.input.c_str(), shaderLabData))
	{
		return 1;
	}

	// parse shaderlab
	shaderlab::SLShader* sourceShader = ParseShaderLab(shaderLabData.c_str(), shaderLabData.size());
	
	// init compiler
	shaderlab::SLCompiler::Init();

	// shader info
	shaderlab::CompileShaderInfo info = { };
	info.shader          = sourceShader;
	info.fileName        = option.input.c_str();
	info.includeCallback = OnLoadInlcudeCallback;

	// compile shader
	shaderlab::SLShader* compiledShader = shaderlab::SLCompiler::Compile(info);

	std::string jsonData = ShaderToJson(compiledShader);

	delete sourceShader;
	delete compiledShader;
	
	FILE* file = fopen(option.output.c_str(), "wb");
	fwrite(jsonData.c_str(), jsonData.size(), 1, file);
	fclose(file);

	printf("Compile completed!");

    return 0;
}

void SLPropValueToJson(Json::Value& data, const shaderlab::SLPropValue& prop)
{
	data["type"] = prop.GetType();
	data["name"] = prop.name;
	data["description"] = prop.description;
	for (int i = 0; i < prop.attributes.size(); ++i) 
	{
		data["attributes"][i] = prop.attributes[i];
	}
	data["value"]["x"] = prop.value[0];
	data["value"]["y"] = prop.value[1];
	data["value"]["z"] = prop.value[2];
	data["value"]["w"] = prop.value[3];

	data["texture"]["name"] = prop.texture.name;
	data["texture"]["dimension"] = prop.texture.GetTextureDimension();
}

void SLFloatToJson(Json::Value& data, const shaderlab::SLFloat& val)
{
	data["val"] = val.val;
	data["ref"] = val.ref;
}

void SLStencilToJson(Json::Value& data, const shaderlab::SLStencilOperation & val)
{
	data["comp"]  = val.comp.val;
	data["pass"]  = val.pass.val;
	data["fail"]  = val.fail.val;
	data["zFail"] = val.zFail.val;
}

void SLStateToJson(Json::Value& data, const shaderlab::SLShaderState& state)
{
	data["lod"]  = state.lod;
	data["name"] = state.name;
	for (auto it = state.tags.begin(); it != state.tags.end(); ++it) 
	{
		data["tags"][it->first] = it->second;
	}
	SLFloatToJson(data["colMask"],			state.colMask);
	SLFloatToJson(data["alphaToMask"],		state.alphaToMask);
	SLFloatToJson(data["offsetFactor"],		state.offsetFactor);
	SLFloatToJson(data["offsetUnits"],		state.offsetUnits);
	SLFloatToJson(data["zTest"],			state.zTest);
	SLFloatToJson(data["zWrite"],			state.zWrite);
	SLFloatToJson(data["culling"],			state.culling);
	SLFloatToJson(data["blendOp"],			state.blendOp);
	SLFloatToJson(data["blendOpAlpha"],		state.blendOpAlpha);
	SLFloatToJson(data["srcBlend"],			state.srcBlend);
	SLFloatToJson(data["destBlend"],		state.destBlend);
	SLFloatToJson(data["srcBlendAlpha"],	state.srcBlendAlpha);
	SLFloatToJson(data["destBlendAlpha"],	state.destBlendAlpha);
	SLFloatToJson(data["stencilRef"],		state.stencilRef);
	SLFloatToJson(data["stencilReadMask"],  state.stencilReadMask);
	SLFloatToJson(data["stencilWriteMask"],	state.stencilWriteMask);
	SLStencilToJson(data["stencilOp"],		state.stencilOp);
	SLStencilToJson(data["stencilOpFront"], state.stencilOpFront);
	SLStencilToJson(data["stencilOpBack"],	state.stencilOpBack);
}

void SLProgramToJson(Json::Value& data, const shaderlab::SLProgram& program)
{
	data["type"]  = program.GetType();
	data["souce"] = program.source;
}

void SLProgramToJson(Json::Value& data, const shaderlab::SLCompiledProgram* program)
{
	data["shaderStage"]  = GetShaderStage(program->shaderStage);
	data["shaderTarget"] = GetShaderTarget(program->shaderTarget);
	data["entryPoint"]   = program->entryPoint;
	for (int32 i = 0; i < program->keywords.size(); ++i)
	{
		data["keywords"][i] = program->keywords[i];
	}

	if (program->shaderTarget == ShaderTarget::kShaderTargetHLSL || program->shaderTarget == ShaderTarget::kShaderTargetVulkan)
	{
		std::string base64Data;
		Base64Encode(program->data.data(), program->data.size(), base64Data);

		data["data"]   = base64Data;
		data["encode"] = "base64";
	}
	else
	{
		std::string stringData(program->data.begin(), program->data.end());

		data["data"]   = stringData;
		data["encode"] = "string";
	}
}

void SLPassToJson(Json::Value& data, const shaderlab::SLPassBase* basePass)
{
	if (basePass->type == shaderlab::SLPassBase::kPassNormal)
	{
		const shaderlab::SLNormalPass* pass = (const shaderlab::SLNormalPass*)basePass;

		data["type"] = "normalPass";
		SLStateToJson(data["state"], pass->state);
		SLProgramToJson(data["program"], pass->program);
	}
	else if (basePass->type == shaderlab::SLPassBase::kPassCompiled)
	{
		const shaderlab::SLCompiledPass* pass = (const shaderlab::SLCompiledPass*)basePass;
		data["type"] = "compiledPass";
		data["errorMsg"] = pass->errorMsg;
		SLStateToJson(data["state"], pass->state);
		for (int32 i = 0; i < pass->programs.size(); ++i)
		{
			SLProgramToJson(data["programs"][i], pass->programs[i]);
		}
	}
	else if (basePass->type == shaderlab::SLPassBase::kPassUse)
	{
		const shaderlab::SLUsePass* pass = (const shaderlab::SLUsePass*)basePass;

		data["type"]    = "usePass";
		data["useName"] = pass->useName;
	}
}

void SLSubShaderToJson(Json::Value& data, const shaderlab::SLSubShader* subShader)
{
	data["lod"] = subShader->lod;

	for (auto it = subShader->tags.begin(); it != subShader->tags.end(); ++it)
	{
		data["tags"][it->first] = it->second;
	}

	for (int32 i = 0; i < subShader->passes.size(); ++i)
	{
		SLPassToJson(data["passes"][i], subShader->passes[i]);
	}
}

std::string ShaderToJson(const shaderlab::SLShader* shader)
{
	Json::Value data;

	data["shaderName"]   = shader->shaderName;
	data["fallbackName"] = shader->fallbackName;

	for (int32 i = 0; i < shader->properties.props.size(); ++i)
	{
		SLPropValueToJson(data["properties"], shader->properties.props[i]);
	}

	for (int32 i = 0; i < shader->subShaders.size(); ++i)
	{
		SLSubShaderToJson(data["subShaders"][i], shader->subShaders[i]);
	}

	Json::FastWriter fastWsriter;
	fastWsriter.omitEndingLineFeed();

	std::string jsonString = fastWsriter.write(data);
	return jsonString;
}