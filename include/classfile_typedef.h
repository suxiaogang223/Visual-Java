#pragma once
#include"jvm_typedef.h"



typedef struct{
	u2 name_index;
}CONSTANT_Class_info;

typedef struct {
	u2 class_index;
	u2 name_and_type_index;
}CONSTANT_Fieldref_info,CONSTANT_Methodref_info,CONSTANT_InterfaceMethodref_info;

typedef struct {
	u2 string_index;
}CONSTANT_String_info;

typedef struct {
	u4 bytes;
}CONSTANT_Integer_info,CONSTANT_Float_info;

typedef struct {
	u4 high_bytes;
	u4 low_bytes;
}CONSTANT_Long_info,CONSTANT_Double_info;

typedef struct {
	u2 name_index;
	u2 descriptor_index;
}CONSTANT_NameAndType_info;

typedef struct {
	u2 length;
	char *bytes;
}CONSTANT_Utf8_info;

typedef struct {
	u1 reference_kind;
	u2 reference_index;
}CONSTANT_MethodHandle_info;

typedef struct {
	u2 descriptor_index;
}CONSTANT_MethodType_info;

typedef struct {
	u2 bootstrap_method_attr_index;
	u2 name_and_type_index;
}CONSTANT_InvokeDynamic_info;

typedef struct {
	u1 tag;
	union {
		CONSTANT_Class_info class_info;
		CONSTANT_Double_info double_info;
		CONSTANT_Float_info float_info;
		CONSTANT_Fieldref_info fieldref_info;
		CONSTANT_Integer_info integer_info;
		CONSTANT_InterfaceMethodref_info interfaceMethodref_info;
		CONSTANT_InvokeDynamic_info invokeDynamic_info;
		CONSTANT_Long_info long_info;
		CONSTANT_MethodHandle_info methodHandle_info;
		CONSTANT_Methodref_info methodref_info;
		CONSTANT_MethodType_info methodType_info;
		CONSTANT_NameAndType_info nameAndType_info;
		CONSTANT_String_info string_info;
		CONSTANT_Utf8_info utf8_info;
	};
}CpInfo;


typedef u2 InterfacesInfo;

typedef struct {
	u2 attribute_name_index;
	u4 attribute_length;
	char* info;
}AttributeInfo;

typedef struct {
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	AttributeInfo *attributes;
}FieldInfo,MethodInfo;

typedef struct {
	u2 max_stack;
	u2 max_locals;
	u4 code_length;
	char *codes;
}Code_attribute;


//TODO 需改进
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