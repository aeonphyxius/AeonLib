#ifndef TYPES_H_
#define TYPES_H_

#include <math.h>

// Vector2 type
typedef struct Vector2 {
	float x;
	float y;
} Vector2;


typedef struct Matrix {
	float m0, m4, m8, m12;
	float m1, m5, m9, m13;
	float m2, m6, m10, m14;
	float m3, m7, m11, m15;
} Matrix;

#endif  // TYPES_H_