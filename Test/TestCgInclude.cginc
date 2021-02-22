
float TestCGIncludeFunc(float v)
{
	#if defined (TEST1)
	return v * 10;
	#endif

	#if defined (TEST2)
	return v * 12;
	#endif
	
	#if defined (TEST3)
	return v * 13;
	#endif
}