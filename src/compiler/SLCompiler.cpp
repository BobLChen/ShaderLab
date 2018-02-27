#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "hlsl2glsl.h"
#include "glsl_optimizer.h"
#include "SLCompiler.h"
#include "utils/SLStringUtils.h"

namespace shaderlab
{
	static glslopt_ctx *g_GlslOptContext[kShaderTargetCount];

	static const int g_semanticSize = 11;
	static const EAttribSemantic g_AttribSemantic[g_semanticSize] = {
		EAttrSemPosition,
		EAttrSemColor0,
		EAttrSemNormal,
		EAttrSemTex0,
		EAttrSemTex1,
		EAttrSemTex2,
		EAttrSemTex3,
		EAttrSemTex4,
		EAttrSemTex5,
		EAttrSemTex6,
		EAttrSemTex7
	};

	static const char* g_AttribString[g_semanticSize] = {
		"xlat_attrib_POSITION",
		"xlat_attrib_COLOR",
		"xlat_attrib_NORMAL",
		"xlat_attrib_TEXCOORD0",
		"xlat_attrib_TEXCOORD1",
		"xlat_attrib_TEXCOORD2",
		"xlat_attrib_TEXCOORD3",
		"xlat_attrib_TEXCOORD4",
		"xlat_attrib_TEXCOORD5",
		"xlat_attrib_TEXCOORD6",
		"xlat_attrib_TEXCOORD7"
	};

	static const char* kGlslTypeNames[kGlslTypeCount] = {
		"float",
		"int",
		"bool",
		"2D",
		"3D",
		"CUBE",
		"2dshadow",
		"2darray",
		"other",
	};
	
	static const char* kGlslPrecNames[kGlslPrecCount] = {
		"high",
		"medium",
		"low",
	};
	
	string GetShaderTargetName(ShaderTarget shaderTarget) 
	{
		if (shaderTarget == kShaderTargetOpenGL) {
			return "opengl";
		} else if (shaderTarget == kShaderTargetGLES20) {
			return "gles20";
		} else if (shaderTarget == kShaderTargetGLES30) {
			return "gles30";
		}
		return "gles20";
	}

	ShaderTarget GetShaderTarget(const string &name) 
	{
		if (strcmp(name.c_str(), "opengl") == 0) {
			return kShaderTargetOpenGL;
		} else if (strcmp(name.c_str(), "gles20") == 0) {
			return kShaderTargetGLES20;
		} else if (strcmp(name.c_str(), "gles30") == 0) {
			return kShaderTargetGLES30;
		}
		return kShaderTargetGLES20;
	}

	void InitializeCompiler()
	{
		Hlsl2Glsl_Initialize();
		g_GlslOptContext[kShaderTargetOpenGL] = glslopt_initialize(kGlslTargetOpenGL);
		g_GlslOptContext[kShaderTargetGLES20] = glslopt_initialize(kGlslTargetOpenGLES20);
		g_GlslOptContext[kShaderTargetGLES30] = glslopt_initialize(kGlslTargetOpenGLES30);
	}
	
	void ShutdownCompiler()
	{
		Hlsl2Glsl_Shutdown();
		glslopt_cleanup(g_GlslOptContext[kShaderTargetOpenGL]);
		glslopt_cleanup(g_GlslOptContext[kShaderTargetGLES20]);
		glslopt_cleanup(g_GlslOptContext[kShaderTargetGLES30]);
	}

	static size_t FindExtensionPos(const std::string &source)
	{
		size_t lastExtensionPos = 0;
		bool extensionFound = false;
		while (true) {
			size_t extensionPos = IndexOfToken(source, "#extension ", lastExtensionPos);
			if (extensionPos == std::string::npos) {
				break;
			}
			extensionFound = true;
			lastExtensionPos = extensionPos + 1;
		}
		if (extensionFound) {
			return SkipToNextLine (source, lastExtensionPos);
		}
		return 0;
	}

	void OptimizeGLSL(glslopt_ctx *ctx, std::string &source, std::string &binds, ShaderProgram type)
	{
		static glslopt_shader_type kTypes[kProgramCount] = { 
			kGlslOptShaderVertex, 
			kGlslOptShaderFragment, 
			(glslopt_shader_type) - 1 
		};
		
		glslopt_shader* shader = glslopt_optimize(ctx, kTypes[type], source.c_str(), 0);

		if (!glslopt_get_status(shader)) {
			source += "/* NOTE: GLSL optimization failed\n";
			source += glslopt_get_log(shader);
			source += "*/\n";
		} else {
			source = glslopt_get_output(shader);
			// input
			const int inputCout = glslopt_shader_get_input_count(shader);
			for (int i = 0; i < inputCout; ++i) {
				const char *parName;
				glslopt_basic_type parType;
				glslopt_precision parPrec;
				int parVecSize, parMatSize, parArrSize, location;
				glslopt_shader_get_input_desc(shader, i, &parName, &parType, &parPrec, &parVecSize, &parMatSize, &parArrSize, &location);
				if (type == kGlslOptShaderVertex) {
					std::string inputName = parName;
					binds += "Bind \"" + inputName + "\"" + " " + inputName.substr(12, inputName.size()) + " " + std::to_string(parVecSize) + "\n";
				}
			}
			// uniforms
			const int uniformCount = glslopt_shader_get_uniform_count(shader);
			for (int i = 0; i < uniformCount; ++i) {
				const char* parName;
				glslopt_basic_type parType;
				glslopt_precision parPrec;
				int parVecSize, parMatSize, parArrSize, location;
				glslopt_shader_get_uniform_desc(shader, i, &parName, &parType, &parPrec, &parVecSize, &parMatSize, &parArrSize, &location);
				if (parVecSize == 1 && parMatSize == 1) {
					binds += "Float " + std::to_string(location) + " [" + parName + "] " + std::to_string(parArrSize) + "\n";
				} else if (parVecSize > 1 && parMatSize == 1) {
					binds += "Vector " + std::to_string(location) + " [" + parName + "] " + std::to_string(parVecSize) + " " + std::to_string(parArrSize) + "\n";
				} else {
					binds += "Matrix " + std::to_string(location) + " [" + parName + "] " + std::to_string(parVecSize) + " " + std::to_string(parMatSize) + " " + std::to_string(parArrSize) + "\n";
				}
			}
			// textures
			const int textureCount = glslopt_shader_get_texture_count(shader);
			for (int i = 0; i < textureCount; ++i) {
				const char* parName;
				glslopt_basic_type parType;
				glslopt_precision parPrec;
				int parVecSize, parMatSize, parArrSize, location;
				glslopt_shader_get_texture_desc(shader, i, &parName, &parType, &parPrec, &parVecSize, &parMatSize, &parArrSize, &location);
				binds += "SetTexture " + std::to_string(location) + " [" + parName + "] " + kGlslTypeNames[parType] + " " + std::to_string(i) + "\n";
			}
		}
		
		glslopt_shader_delete(shader);
	}

	ETargetVersion GetTargetVersion(ShaderTarget shaderTarget)
	{
		if (shaderTarget == kShaderTargetGLES20) {
			return ETargetGLSL_ES_100;
		} else if (shaderTarget == kShaderTargetGLES30) {
			return ETargetGLSL_ES_300;
		} else {
			return ETargetGLSL_120;
		}
	}

	std::string PreprocessGLES3FragmentShader(const std::string &source)
	{
		std::string result;

		if (source.find("gl_FragColor") != std::string::npos) {
			result += "#define gl_FragColor _gles3FragColor\n";
			result += "layout(location = 0) out mediump vec4 _gles3FragColor;\n";
		}

		if (source.find("gl_FragData") != std::string::npos) {
			result += "#define gl_FragData _gles3FragData\n";
			result += "layout(location = 0) out mediump vec4 _gles3FragData[4];\n";
		}

		size_t extensionPos = FindExtensionPos(source);
		result = source.substr(0, extensionPos) + result;
		result += source.substr(extensionPos, source.size() - extensionPos);
		
		return result;
	}

	void CompileHLSL2GLSL(ShaderCompileData &data) 
	{
		if (data.params->entryName[kProgramVertex].empty() || data.params->entryName[kProgramFragment].empty()) {
			printf("glsl requires both vertex and fragment programs.\n");
			return;
		}

		std::string defines;
		for (size_t i = 0, n = data.args.size() ; i < n ; ++i ) {
			defines += "#ifndef " + data.args[i].name + "\n";
			defines += "    #define " + data.args[i].name + " " + data.args[i].value + "\n";
			defines += "#endif\n";
		}

		std::string source = defines + data.params->source;
		ReplaceString(source, "#pragma", "// #pragma");

		ShHandle vertParser = Hlsl2Glsl_ConstructCompiler(EShLangVertex);
		ShHandle fragParser = Hlsl2Glsl_ConstructCompiler(EShLangFragment);

		const int options = 0;
		const ETargetVersion targetVersion = GetTargetVersion(data.shaderTarget);
		
		Hlsl2Glsl_ParseCallbacks parseCallbacks;
		parseCallbacks.includeOpenCallback  = data.params->includeOpenCallback;
		parseCallbacks.includeCloseCallback = NULL;
		
		if (!Hlsl2Glsl_Parse(vertParser, source.c_str(), targetVersion, &parseCallbacks, options)) {
			const char *infoLog = Hlsl2Glsl_GetInfoLog(vertParser);
			printf("GLSL vertex shader: %s\n", infoLog);
			Hlsl2Glsl_DestructCompiler(vertParser);
			Hlsl2Glsl_DestructCompiler(fragParser);
			return;
		}

		if (!Hlsl2Glsl_Parse(fragParser, source.c_str(), targetVersion, &parseCallbacks, options)) {
			const char *infoLog = Hlsl2Glsl_GetInfoLog(fragParser);
			printf("GLSL fragment shader:%s\n", infoLog);
			Hlsl2Glsl_DestructCompiler(vertParser);
			Hlsl2Glsl_DestructCompiler(fragParser);
			return;
		}

		Hlsl2Glsl_SetUserAttributeNames(vertParser, g_AttribSemantic, g_AttribString, g_semanticSize);
		Hlsl2Glsl_SetUserAttributeNames(fragParser, g_AttribSemantic, g_AttribString, g_semanticSize);
		
		if (!Hlsl2Glsl_Translate(vertParser, data.params->entryName[kProgramVertex].c_str(), targetVersion, options)) {
			const char *infoLog = Hlsl2Glsl_GetInfoLog(vertParser);
			printf("GLSL translate vertex: %s\n", infoLog);
			Hlsl2Glsl_DestructCompiler(vertParser);
			Hlsl2Glsl_DestructCompiler(fragParser);
			return;
		}
		std::string glslVertCode = Hlsl2Glsl_GetShader(vertParser);
		
		if (!Hlsl2Glsl_Translate(fragParser, data.params->entryName[kProgramFragment].c_str(), targetVersion, options)) {
			const char *infoLog = Hlsl2Glsl_GetInfoLog(fragParser);
			printf("GLSL translate fragment: %s\n", infoLog);
			Hlsl2Glsl_DestructCompiler(vertParser);
			Hlsl2Glsl_DestructCompiler(fragParser);
			return;
		}
		std::string glslFragCode = Hlsl2Glsl_GetShader(fragParser);

		if (data.shaderTarget == kShaderTargetGLES30) {
			glslFragCode = PreprocessGLES3FragmentShader(glslFragCode);
		}
		
		glslopt_ctx* ctx = g_GlslOptContext[data.shaderTarget];
		glslVertCode = defines + glslVertCode;
		glslFragCode = defines + glslFragCode;

		ReplaceString(glslVertCode, "#version ", "// #version ");
		ReplaceString(glslFragCode, "#version ", "// #version ");

		if (data.shaderTarget == kShaderTargetGLES30) {
			glslVertCode = "#version 300 es\n" + glslVertCode;
			glslFragCode = "#version 300 es\n" + glslFragCode;
		}
		
		OptimizeGLSL(ctx, glslVertCode, data.vertBinds, kProgramVertex);
		OptimizeGLSL(ctx, glslFragCode, data.fragBinds, kProgramFragment);

		data.output += "#ifdef VERTEX\n"   + glslVertCode + "\n#endif\n";
		data.output += "#ifdef FRAGMENT\n" + glslFragCode + "\n#endif\n";

		Hlsl2Glsl_DestructCompiler(vertParser);
		Hlsl2Glsl_DestructCompiler(fragParser);
	}

	void CompileShaderProgram(CGProgramParameters &params, string &compiled) 
	{
		vector<ShaderCompileArg> args;
		string keywords0 = "";
		string keywords1 = "Keywords: ";
		size_t keywordsSize = params.keywords.size();
		for (size_t i = 0; i < keywordsSize; ++i) {
			args.push_back(ShaderCompileArg(params.keywords[i], "1"));
			keywords0 += "\"" + params.keywords[i] + "\" ";
			keywords1 += params.keywords[i] + (i + 1 == keywordsSize ? "" : ", ");
		}
		
		string vpresult;
		string fpresult;
		for (int apiIdx = 0; apiIdx < kShaderTargetCount; ++apiIdx) {
			if ((params.shaderTarget & (1 << apiIdx)) == 0) {
				continue;
			}
			ShaderCompileData compileData;
			compileData.args = args;
			compileData.params = &params;
			compileData.keywords = keywords1;
			compileData.shaderTarget = (ShaderTarget)apiIdx;
			
			CompileHLSL2GLSL(compileData);
			
			string vpcode;
			ExtractBlockString(compileData.output, vpcode, "#ifdef VERTEX", "#endif");
			string fpcode;
			ExtractBlockString(compileData.output, fpcode, "#ifdef FRAGMENT", "#endif");

			vpresult += "SubProgram \"" + GetShaderTargetName(compileData.shaderTarget) + "\" {\nKeywords { " + keywords0 + "}\n";;
			vpresult += compileData.vertBinds;
			vpresult += "\"" + vpcode + "\"\n}\n\n";
			fpresult += "SubProgram \"" + GetShaderTargetName(compileData.shaderTarget) + "\" {\nKeywords { " + keywords0 + "}\n";;
			fpresult += compileData.fragBinds;
			fpresult += "\"" + fpcode + "\"\n}\n\n";
		}

		compiled += string("Program \"") + "vp" + "\" {\n" + vpresult + "}\n";
		compiled += string("Program \"") + "fp" + "\" {\n" + fpresult + "}\n";
	}
	
	void ProcessPragmaArgs(const string &text, const string &pragmaName, vector<vector<string>> &params)
	{
		size_t pos = IndexOfToken(text, pragmaName, 0);
		while (pos != string::npos) {
			pos += pragmaName.size();
			string line = ReadLine(text, pos);
			size_t linePos = 0;
			vector<string> names;
			while (linePos < line.size()) {
				string token = ReadNonWhiteSpace(line, linePos);
				if (token.empty()) {
					break;
				}
				names.push_back(token);
			}
			params.push_back(names);
			pos = IndexOfToken(text, pragmaName, pos);
		}
	}

	void ProcessCGProgram(IncludeOpenCallback includeOpenCallback, const string &codeString, string &output)
	{
		vector<vector<string>> pragmaParams;
		ProcessPragmaArgs(codeString, "#pragma ", pragmaParams);
		CGProgramParameters params;
		params.includeOpenCallback = includeOpenCallback;
		params.source = codeString;
		params.SetPragmaParams(pragmaParams);
		CompileShaderProgram(params, output);
	}
	
	void ProcessShaderLab(IncludeOpenCallback includeOpenCallback, string &source, const string &includeBegin, const string &includeEnd, const string &programBegin, const string &programEnd)
	{
		string includeCode;
		ExtractBlockString(source, includeCode, includeBegin, includeEnd);
		size_t begin = IndexOfToken(source, programBegin, 0);
		while (begin != string::npos) {
			size_t end = IndexOfToken(source, programEnd, begin);
			if (end == string::npos) {
				return;
			}
			string progCode = includeCode + source.substr(begin + programBegin.size(), end - begin - programBegin.size());
			string compiled;
			ProcessCGProgram(includeOpenCallback, progCode, compiled);
			source = source.erase(begin, end + programEnd.size() - begin);
			source.insert(begin, compiled);
			begin = IndexOfToken(source, programBegin, begin);
		}
	}

	bool compileCG(const std::string &source, IncludeOpenCallback includeOpenCallback, std::string &output)
	{
		output = source;
		InitializeCompiler();
		ProcessShaderLab(includeOpenCallback, output, "CGINCLUDE", "ENDCG", "CGPROGRAM", "ENDCG");
		ShutdownCompiler();
		return true;
	}
}

