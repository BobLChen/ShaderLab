# ShaderLab

仿Unity Shaderlab的Shader跨平台编译器。使用[DirectX Shader Compiler](https://github.com/Microsoft/DirectXShaderCompiler)以及[GLSLang](https://github.com/KhronosGroup/glslang)编译器作为前端，[SPIRV-Cross](https://github.com/KhronosGroup/SPIRV-Cross)作为后端，将`HLSL`以及`GLSL`编译成`DXIL`、`SPIR-V`、`HLSL`、`Metal`和`GLSL`。

内置一个`ShaderCross`可执行程序，可对`*.shaderlab`编译成对应平台的`Shader`并以`Json`的方式输出。

## 环境

- **Git**：安装git，配置好环境。
- **Visual Studio 2017**：任意版本即可。
- **CMake**：越新越好，至少3.9。
- **Python**：任意版本，配置好环境。

## 构建

- 打开CMakeGUI
- `Where is the source code`选择`Path/ShaderLab`
- `Where is the build the binaries`选择`Path/ShaderLab/Build`
- 点击`Configure`，选择`Visual Studio 2017 x64`
- 点击`Generate`
- 点击`Open Project`

## ShaderLab

ShaderLab is a tool designed for cross-compiling unity shaderlab to other shading languages.

## Prerequisites

- **Git**
- **Visual Studio 2017**
- **CMake** 
- **Python**

## Building

```bash
 mkdir Build
 cd Build
 cmake -G "Visual Studio 15" ../
```

## License

MIT License