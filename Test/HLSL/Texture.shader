Shader "Test/Texture" 
{
	Properties 
	{
		g_texture ("Texture", 2D) = "white" {}
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

				struct PSInput
                {
                    float4 position : SV_POSITION;
                    float2 uv       : TEXCOORD;
                };

                Texture2D g_texture    : register(t0);
                SamplerState g_sampler : register(s0);

                PSInput vert(float4 position : POSITION, float4 uv : TEXCOORD)
                {
                    PSInput result;

                    result.position = position;
                    result.uv = uv;

                    return result;
                }

                float4 frag(PSInput input) : SV_TARGET
                {
                    return g_texture.Sample(g_sampler, input.uv);
                }

				ENDCG
			}
		}
	}
}
