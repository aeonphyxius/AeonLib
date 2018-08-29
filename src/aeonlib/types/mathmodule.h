#ifndef MATH_MODULE_H_
#define MATH_MODULE_H_

#include "types.h"

#ifdef __cplusplus
#define RMEXTERN extern "C"     // Functions visible from other files (no name mangling of functions in C++)
#else
#define RMEXTERN extern         // Functions visible from other files
#endif

#if defined(RAYMATH_EXTERN_INLINE)
#define RMDEF RMEXTERN inline   // Functions are embeded inline (compiler generated code)
#else
#define RMDEF RMEXTERN
#endif


// Returns identity matrix
RMDEF Matrix MatrixIdentity(void)
{
	Matrix result = { 1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f };

	return result;
}

#endif  // MATH_MODULE_H_