#include <Windows.h>
#include <d3d12shader.h>
#include <xstring>
#include <atomic>

#include "HLSLCompiler.h"

#include "dxc/Support/Global.h"
#include "dxc/Support/Unicode.h"
#include "dxc/Support/WinAdapter.h"
#include "dxc/Support/WinIncludes.h"

#include "dxc/DxilContainer/DxilContainer.h"
#include "dxc/dxcapi.h"

#include "spirv-tools/libspirv.h"
#include "spirv.hpp"
#include "spirv_cross.hpp"
#include "spirv_glsl.hpp"
#include "spirv_hlsl.hpp"
#include "spirv_msl.hpp"
#include "spirv_cross_util.hpp"

namespace shaderlab
{
	static HMODULE						G_DXCompilerDLL = nullptr;
	static DxcCreateInstanceProc		G_CreateInstanceFunc = nullptr;
	static IDxcLibrary*					G_DXLibrary = nullptr;
	static IDxcCompiler*				G_DXCompiler = nullptr;
	static IDxcContainerReflection*		G_DXContainerReflection = nullptr;

	class ScIncludeHandler : public IDxcIncludeHandler
	{
	public:

		explicit ScIncludeHandler(std::function<std::string(const char* includeName)> loadCallback)
			: m_LoadCallback(std::move(loadCallback))
		{

		}

		HRESULT STDMETHODCALLTYPE LoadSource(LPCWSTR fileName, IDxcBlob** includeSource) override
		{
			if ((fileName[0] == L'.') && (fileName[1] == L'/'))
			{
				fileName += 2;
			}

			std::string utf8FileName;
			if (!Unicode::UTF16ToUTF8String(fileName, &utf8FileName))
			{
				return E_FAIL;
			}

			std::string includeData = m_LoadCallback(utf8FileName.c_str());
			
			*includeSource = nullptr;
			return G_DXLibrary->CreateBlobWithEncodingOnHeapCopy(includeData.c_str(), includeData.size(), CP_UTF8, reinterpret_cast<IDxcBlobEncoding**>(includeSource));
		}

		ULONG STDMETHODCALLTYPE AddRef() override
		{
			++m_Ref;
			return m_Ref;
		}

		ULONG STDMETHODCALLTYPE Release() override
		{
			--m_Ref;
			ULONG result = m_Ref;
			if (result == 0)
			{
				delete this;
			}
			return result;
		}

		HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** object) override
		{
			if (IsEqualIID(iid, __uuidof(IDxcIncludeHandler)))
			{
				*object = dynamic_cast<IDxcIncludeHandler*>(this);
				this->AddRef();
				return S_OK;
			}
			else if (IsEqualIID(iid, __uuidof(IUnknown)))
			{
				*object = dynamic_cast<IUnknown*>(this);
				this->AddRef();
				return S_OK;
			}
			else
			{
				return E_NOINTERFACE;
			}
		}

	private:
		std::function<std::string(const char* includeName)>		m_LoadCallback;
		std::atomic<ULONG>										m_Ref = 0;
	};

	bool HLSLCompiler::Init()
	{
		if (G_DXCompilerDLL != nullptr)
		{
			return true;
		}

		const char* dllName      = "dxcompiler.dll";
		const char* functionName = "DxcCreateInstance";

		G_DXCompilerDLL = ::LoadLibraryA(dllName);

		if (G_DXCompilerDLL != nullptr)
		{
			G_CreateInstanceFunc = (DxcCreateInstanceProc)::GetProcAddress(G_DXCompilerDLL, functionName);

			if (G_CreateInstanceFunc != nullptr)
			{
				G_CreateInstanceFunc(CLSID_DxcLibrary,             __uuidof(IDxcLibrary),             reinterpret_cast<void**>(&G_DXLibrary));
				G_CreateInstanceFunc(CLSID_DxcCompiler,            __uuidof(IDxcCompiler),            reinterpret_cast<void**>(&G_DXCompiler));
				G_CreateInstanceFunc(CLSID_DxcContainerReflection, __uuidof(IDxcContainerReflection), reinterpret_cast<void**>(&G_DXContainerReflection));
			}
			else
			{
				Destroy();
				return false;
			}
		}
		else
		{
			Destroy();
			return false;
		}

		return true;
	}

	bool HLSLCompiler::Destroy()
	{
		if (G_DXCompilerDLL != nullptr)
		{
			::FreeLibrary(G_DXCompilerDLL);

			G_DXLibrary             = nullptr;
			G_DXCompiler            = nullptr;
			G_DXCompilerDLL         = nullptr;
			G_CreateInstanceFunc    = nullptr;
			G_DXContainerReflection = nullptr;
		}

		return true;
	}

	HLSLCompileResult HLSLCompiler::Compile(const ShaderSnippet& snippet)
	{
		HLSLCompileResult hlslCompileResult;

		// shader profile
		std::wstring shaderProfile = ShaderProfileName(snippet.stage, snippet.shaderModel);

		// defines
		std::vector<DxcDefine> dxcDefines;
		std::vector<std::wstring> tempStrings;
		tempStrings.reserve(snippet.defines.size() * 2);

		for (int32 i = 0; i < snippet.defines.size(); ++i)
		{
			const MacroDefine& define = snippet.defines[i];
			const wchar_t* nameUtf16  = nullptr;
			const wchar_t* valueUtf16 = nullptr;

			if (!define.name.empty())
			{
				std::wstring utf16Str;
				Unicode::UTF8ToUTF16String(define.name.c_str(), &utf16Str);
				tempStrings.emplace_back(std::move(utf16Str));
				nameUtf16 = tempStrings.back().c_str();
			}

			if (!define.value.empty())
			{
				std::wstring utf16Str;
				Unicode::UTF8ToUTF16String(define.value.c_str(), &utf16Str);
				tempStrings.emplace_back(std::move(utf16Str));
				valueUtf16 = tempStrings.back().c_str();
			}

			if (nameUtf16 != nullptr)
			{
				dxcDefines.push_back({ nameUtf16, valueUtf16 });
			}
		}

		// source blob
		IDxcBlobEncoding* sourceBlob;
		G_DXLibrary->CreateBlobWithEncodingOnHeapCopy(snippet.source, snippet.sourceLength, CP_UTF8, &sourceBlob);

		// filename
		std::wstring shaderNameUtf16;
		Unicode::UTF8ToUTF16String(snippet.fileName, &shaderNameUtf16);

		// entry point
		std::wstring entryPointUtf16;
		Unicode::UTF8ToUTF16String(snippet.entryPoint, &entryPointUtf16);

		// args
		std::vector<std::wstring> dxcArgStrings;
		dxcArgStrings.push_back(L"-Zpr");
		dxcArgStrings.push_back(L"-O3");
		if (snippet.shaderTarget != ShaderTarget::kShaderTargetHLSL)
		{
			dxcArgStrings.push_back(L"-spirv");
		}

		std::vector<const wchar_t*> dxcArgWChars;
		dxcArgWChars.reserve(dxcArgStrings.size());
		for (int32 i = 0; i < dxcArgStrings.size(); ++i)
		{
			dxcArgWChars.push_back(dxcArgStrings[i].c_str());
		}

		// compile
		IDxcIncludeHandler* includeHandler = new ScIncludeHandler(std::move(snippet.includeCallback));
		IDxcOperationResult* compileResult = nullptr;
		G_DXCompiler->Compile(
			sourceBlob,
			shaderNameUtf16.c_str(),
			entryPointUtf16.c_str(),
			shaderProfile.c_str(),
			dxcArgWChars.data(),
			dxcArgWChars.size(),
			dxcDefines.data(),
			dxcDefines.size(),
			includeHandler,
			&compileResult
		);
		sourceBlob->Release();

		// get result
		HRESULT compileStatus;
		compileResult->GetStatus(&compileStatus);

		// get warning & error msg
		IDxcBlobEncoding* compileErrors = nullptr;
		compileResult->GetErrorBuffer(&compileErrors);
		if (compileErrors != nullptr)
		{
			const char* buffer = (const char*)compileErrors->GetBufferPointer();
			hlslCompileResult.warningErrorMsg = std::string(buffer, buffer + compileErrors->GetBufferSize());
			compileErrors->Release();
		}

		if (SUCCEEDED(compileStatus))
		{
			IDxcBlob* program = nullptr;
			compileResult->GetResult(&program);
			compileResult = nullptr;

			if (program != nullptr)
			{
				const char* buffer = (const char*)program->GetBufferPointer();
				hlslCompileResult.data.reserve(program->GetBufferSize());
				hlslCompileResult.data.resize(program->GetBufferSize());
				memcpy(hlslCompileResult.data.data(), buffer, program->GetBufferSize());
				program->Release();
			}
		}

		return hlslCompileResult;
	}
}