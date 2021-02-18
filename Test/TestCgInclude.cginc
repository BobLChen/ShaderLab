
float test_cg_include_file(float v)
{
	#if defined (LIGHTING)
	return v * 10;
	#endif
	#if defined (SHADOW)
	return v * 12;
	#endif
	#if defined (LIGHTMAP)
	return v * 13;
	#endif
}