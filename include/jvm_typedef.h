#pragma once
 #include <stdint.h>//此头文件里包含了uint8_t等跨平台类型

//在虚拟机内部存储的都是字节
//因为c/c++在每个不同的系统中int short long 的长度是不同的
//因此采用这种写法可以保证跨平台的争取性
typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;

// typedef unsigned char u1;
// typedef unsigned short u2;
// typedef unsigned int u4;

//接下来就涉及到为虚拟机的每一个内置类型进行定义

/**Java 类型	本地类型	描述
boolean	jboolean	C/C++8位整型
byte	jbyte	C/C++带符号的8位整型
char	jchar	C/C++无符号的16位整型
short	jshort	C/C++带符号的16位整型
int	jint	C/C++带符号的32位整型
long	jlong	C/C++带符号的64位整型e
float	jfloat	C/C++32位浮点型
double	jdouble	C/C++64位浮点型
Object	jobject	任何Java对象，或者没有对应java类型的对象
Class	jclass	Class对象
String	jstring	字符串对象
Object[]	jobjectArray	任何对象的数组
boolean[]	jbooleanArray	布尔型数组
byte[]	jbyteArray	比特型数组
char[]	jcharArray	字符型数组
short[]	jshortArray	短整型数组
int[]	jintArray	整型数组
long[]	jlongArray	长整型数组
float[]	jfloatArray	浮点型数组
double[]	jdoubleArray	双浮点型数组**/


typedef uint8_t jboolean;
typedef int8_t jbyte;
typedef uint16_t jchar;
typedef int16_t jshort;
typedef int32_t jint;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;
//todo more


//联合类型，在类型转换中使用
union byte_32{
    u4 _u4;
    jboolean _jboolean;
    jbyte _jbyte;
    jchar _jchar;
    jshort _jshort;
    jint _jint;
    jfloat _jfloat;
};

union byte_64{
    u4 _u4[2];
    byte_32 _byte_32[2];//不一定有用
    jlong _jlong;
    jdouble _jdouble;
};

