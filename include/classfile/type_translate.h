#pragma once
#include"classfile_typedef.h"
//这些联合类型可对存储的数据进行类型选择
typedef union {
	char* boolean_array;
	u2* char_array;
	float* float_array;
	double* double_array;
	char* byte_array;
	short* short_array;
	int* int_array;
	long long* long_array;
}arrayType;

typedef union {
	char b;
	short s;
	u2 c;
	int i;
	u4 a;
	float f;
	long long l;
	double d;
}fieldType;

typedef union {
	u4 U4;
	int i;
	//short s[2];
	//u2 c[2];
	//char b[4];
	float f;
}stackType;

typedef union {
	u4 U4[2];
	long long l;
	double d;
}stackType2;

typedef union {
	u2 U2;
	u1 U1[2];
}translate_U2;

typedef union {
	u4 U4;
	u1 U1[4];
}translate_U4;