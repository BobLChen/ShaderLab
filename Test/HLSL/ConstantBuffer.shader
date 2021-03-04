Shader "Test/ConstantBuffer" 
{
	Properties 
	{
		_Diffuse ("Tiling Offset", Vector) = (1.0, 1.0, 1.0, 1.0)
	}
    
	Category
	{

		Tags { "Queue"="Transparent" "IgnoreProjector"="True" "RenderType"="Transparent" }
		
		SubShader 
		{
			Pass 
			{
				CGPROGRAM

				#pragma vertex vert
				#pragma fragment frag
				#pragma target gles30 opengl gles20 ios mac vulkan hlsl

				cbuffer SceneConstantBuffer : register(b0)
                {
                    float4 offset;
                };

                float4 _Diffuse;

                struct PSInput
                {
                    float4 position : SV_POSITION;
                    float4 color : COLOR;
                };

                PSInput vert(float4 position : POSITION, float4 color : COLOR)
                {
                    PSInput result;

                    result.position = position + offset;
                    result.color = color;

                    return result;
                }

                float4 frag(PSInput input) : SV_TARGET
                {
                    return input.color * _Diffuse;
                }

				ENDCG
			}
		}
	}
}
