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

	std::wstring ShaderProfileName(ShaderStage stage, ShaderModel shaderModel)
	{
		std::wstring shaderProfile;

		switch (stage)
		{
		case ShaderStage::kProgramVertex:
			shaderProfile = L"vs";
			break;

		case ShaderStage::kProgramFragment:
			shaderProfile = L"ps";
			break;

		case ShaderStage::kProgramGeometry:
			shaderProfile = L"gs";
			break;

		case ShaderStage::kProgramHull:
			shaderProfile = L"hs";
			break;

		case ShaderStage::kProgramDomain:
			shaderProfile = L"ds";
			break;

		case ShaderStage::kProgramCompute:
			shaderProfile = L"cs";
			break;

		default:
			shaderProfile = L"vs";
			break;
		}

		shaderProfile.push_back(L'_');
		shaderProfile.push_back(L'0' + shaderModel.majorVer);
		shaderProfile.push_back(L'_');
		shaderProfile.push_back(L'0' + shaderModel.minorVer);

		return shaderProfile;
	}

	class HLSLIncludeHandler : public IDxcIncludeHandler
	{
	public:

		explicit HLSLIncludeHandler(IncludeCallback loadCallback)
			: m_LoadCallback(std::move(loadCallback))
			, m_Ref(std::atomic_int(0))
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

			ByteArray bytes = m_LoadCallback(utf8FileName.c_str());
			m_Datas.push_back(bytes);

			*includeSource = nullptr;
			return G_DXLibrary->CreateBlobWithEncodingOnHeapCopy(bytes.data, bytes.size, CP_UTF8, reinterpret_cast<IDxcBlobEncoding**>(includeSource));
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
				ReleaseData();
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

		void ReleaseData()
		{
			for (int32 i = 0; i < m_Datas.size(); ++i)
			{
				delete[] m_Datas[i].data;
			}

			m_Datas.clear();
		}

	private:
		IncludeCallback			m_LoadCallback;
		std::atomic<ULONG>		m_Ref;
		std::vector<ByteArray>	m_Datas;
	};

	bool HLSLCompiler::Init()
	{
		if (G_DXCompilerDLL != nullptr)
		{
			return true;
		}

#if PLATFORM_WINDOWS
		const char* dllName      = "dxcompiler.dll";
#else
		const char* dllName      = "libdxcompiler.so";
#endif
		const char* functionName = "DxcCreateInstance";

#if PLATFORM_WINDOWS
		G_DXCompilerDLL = ::LoadLibraryA(dllName);
#else
		G_DXCompilerDLL = ::dlopen(dllName, RTLD_LAZY);
#endif

		if (G_DXCompilerDLL != nullptr)
		{
#if PLATFORM_WINDOWS
			G_CreateInstanceFunc = (DxcCreateInstanceProc)::GetProcAddress(G_DXCompilerDLL, functionName);
#else
			G_CreateInstanceFunc = (DxcCreateInstanceProc)::dlsym(G_DXCompilerDLL, functionName);
#endif

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
#if PLATFORM_WINDOWS
			::FreeLibrary(G_DXCompilerDLL);
#else
			::dlclose(G_DXCompilerDLL);
#endif
			
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

		ShaderModel shaderModel = { 6, 0 };

		// shader profile
		std::wstring shaderProfile = ShaderProfileName(snippet.shaderStage, shaderModel);

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
		IDxcIncludeHandler* includeHandler = new HLSLIncludeHandler(std::move(snippet.includeCallback));
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
		else
		{
			IDxcBlobEncoding* compileErrors = nullptr;
			compileResult->GetErrorBuffer(&compileErrors);
			if (compileErrors != nullptr)
			{
				const char* buffer = (const char*)compileErrors->GetBufferPointer();
				hlslCompileResult.warningErrorMsg = std::string(buffer, buffer + compileErrors->GetBufferSize());
				compileErrors->Release();
			}
		}

		return hlslCompileResult;
	}
}