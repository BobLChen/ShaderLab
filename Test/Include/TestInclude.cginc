// #include "SubInclude/Math.cginc"

#include "./SubInclude/Math.cginc"

// float Pow5(float v)
// {
//     return v * v * v * v * v;
// }

float TestCGIncludeFunc(float v)
{
#if defined (TEST1)
	return Pow5(v) * 1;
#endif

#if defined (TEST2)
	return Pow5(v) * 2;
#endif
	
#if defined (TEST3)
	return Pow5(v) * 3;
#endif

	return Pow5(v) * 4;
}
